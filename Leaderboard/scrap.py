# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    scrap.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 19:47:53 by ele-lean          #+#    #+#              #
#    Updated: 2024/08/20 18:00:08 by ele-lean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

try:
    import json
    import time
    import os
    import sys
    import subprocess
    import monotonic
    import getpass
    from selenium import webdriver
    from selenium.webdriver.common.by import By
    from selenium.webdriver.support.ui import WebDriverWait
    from selenium.webdriver.support import expected_conditions as EC
    import dropbox
    from pathlib import Path

    DROPBOX_ACCESS_TOKEN = "sl.B7VnfLsB9sZ53ypETHnfb7OXcIK4nKRYinyNqWT0loehWCelcxDwmuuaQPYEeDeFXxXt4BSv25m_Lx8eghQsEvrI9m54SJRK2DI6b3akdcAI6LkvZ-gIiy3rtyxFfYwmdwYqViP1c9oMDavWnkjvjtg"

    dbx = dropbox.Dropbox(DROPBOX_ACCESS_TOKEN)

    prenoms = [
        "ele-lean", "malevieu", "lchauvet", "almeddah", "cpoulain", "jcheron", "tobesnar",
        "ladurand", "edetoh", "releroy", "vseyidov", "tle-goff", "throbert", "lnassar",
        "cabraham", "mduvey", "ghoyaux", "aberenge", "lsellier", "ljacq", "abidaux",
        "cfleuret", "adcisse", "tgoudman", "hdelacou", "hdruel", "nlecreux", "jabertin",
        "huyanan", "mavander", "lvan-bre", "niclambe", "jbastard", "aperceva", "abosc",
        "tolivaud", "calleaum", "emaillet", "rbardet-", "lgrisel", "alegrix", "tharrel",
        "aboutry", "ameduboi", "mgendrot", "tliberse", "mpelleri", "ngaudoui", "etaquet",
        "dbaciu", "mpapin", "minhpham", "fkurti", "jeetienn", "mgarsaul", "guphilip",
        "afolliot", "plerick", "clephal", "pilot-de", "sbenamar", "artgirar", "tlize",
        "maiba", "pthuilli", "ogsimsek", "lleborgn", "luguo", "azhao", "fbriault",
        "mtatar", "salwong", "rdelepin", "mkreko", "lplottin", "isehim", "bperrot",
        "spicque", "abensala", "jtannier", "jhatting", "matgabri", "gdefrace", "abuty",
        "ngilles", "jnicolle", "qgutmann", "davlelie", "taubry", "mflandri", "rbouchou",
        "ansleima", "jgrisoni", "hzwak", "apain", "jliot"
    ]

    print("\033[0;91m!!!WARNING!!! READ THIS BEFORE CONTINUING !!!WARNING!!!\nThis script will ask you for your login, it will be only used to get access to the data.\nThe chances of being flagg by the server are low but you can add a custom delay between each request to slow down the traffic.\nA google chrome page will automatically be opened for the duration of the operation (around 30-35sec with no delay) don't close it, it could mess up the operation.\033[0;0m")
    print("Number of students: " + str(len(prenoms)))

    login = input("Login: ")
    mdp = getpass.getpass('Mdp: ')
    dl = int(input("Delay between each request: "))
    driver = webdriver.Chrome()
    scores = []
    scores_liste = []
    temps_presence_liste = []
    a = monotonic.monotonic()
    try:
        driver.get("https://auth.42.fr/auth/realms/students-42/protocol/openid-connect/auth?client_id=intra")

        username = driver.find_element(By.ID, "username")
        password = driver.find_element(By.ID, "password")

        username.send_keys(login)
        password.send_keys(mdp)
        
        submit_button = driver.find_element(By.ID, "kc-login")
        submit_button.click()
        WebDriverWait(driver, 10).until(
            EC.url_contains("https://profile.intra.42.fr")
        )

        for index, prenom in enumerate(prenoms):
            driver.get(f"https://profile.intra.42.fr/users/{prenom}/skills")

            WebDriverWait(driver, 10).until(
                EC.presence_of_element_located((By.TAG_NAME, "pre"))
            )
            page_content = driver.find_element(By.TAG_NAME, "pre").text
            try:
                skills = json.loads(page_content)
            except json.JSONDecodeError:
                print(f"Erreur de décodage JSON pour {prenom}")
                scores.append(0)
                continue
            total_percent = sum(skill.get("percent", 0) for skill in skills)
            total_level = sum(skill.get("lvl", 0) * 100 for skill in skills)
            score = total_percent + total_level
            scores.append(score)
            scores_liste.append([prenom, score])

            time.sleep(dl)
            driver.get(f"https://translate.intra.42.fr/users/{prenom}/locations_stats.json")
            WebDriverWait(driver, 10).until(
                EC.presence_of_element_located((By.TAG_NAME, "pre"))
            )
            presence_content = driver.find_element(By.TAG_NAME, "pre").text
            try:
                presence_stats = json.loads(presence_content)
                temps_presence = [[jour, temps] for jour, temps in presence_stats.items()]
                temps_presence_liste.append([prenom, temps_presence])
            except json.JSONDecodeError:
                print(f"Erreur de décodage JSON pour les temps de présence de {prenom}")
                temps_presence_liste.append([prenom, []])

            print(f"Score pour {prenom}: {score}")
            print(f"Temps de présence pour {prenom}: {temps_presence}")

            time.sleep(dl)

    finally:
        driver.quit()
        print("Duration of scrapping: " + str(monotonic.monotonic() - a))

    documents_folder = Path.home() / "Documents"
    documents_folder.mkdir(parents=True, exist_ok=True)
    scores_file = documents_folder / "scores.json"
    presence_file = documents_folder / "temps_presence.json"

    with open(scores_file, "w") as fichier:
        json.dump(scores_liste, fichier, indent=4)
    with open(presence_file, "w") as fichier:
        json.dump(temps_presence_liste, fichier, indent=4)

    def upload_to_dropbox(file_path, dropbox_path):
        with open(file_path, "rb") as f:
            dbx.files_upload(f.read(), dropbox_path, mode=dropbox.files.WriteMode.overwrite)
            print(f"File {file_path} uploaded on Dropbox at {dropbox_path}")

    upload_to_dropbox(str(scores_file), f"/{scores_file.name}")
    upload_to_dropbox(str(presence_file), f"/{presence_file.name}")

    print("Scores recieved: " + str(len(scores)))
except Exception as e:
	print("\033[0;91m")
	exc_type, exc_obj, exc_tb = sys.exc_info()
	fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
	print(exc_type, fname, exc_tb.tb_lineno)
	a = input("Multiple modules are required to run this script do you wanna try to automatically install them ?")
	def install(package):
		subprocess.check_call([sys.executable, "-m", "pip", "install", package])
	required_modules = [
		"dropbox",
		"json",
		"selenium",
		"monotonic",
		"getpass",
		"time",
		"pathlib"
	]
	for module in required_modules:
		try:
			__import__(module)
		except ImportError:
			print(f"Module {module} non trouvé, installation...")
			install(module)
		else:
			print(f"Module {module} déjà installé.")
	print("if it's still not working you can try 'sudo apt-get install chromium-chromedriver'\033[0;0m")