# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    scrap.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 19:47:53 by ele-lean          #+#    #+#              #
#    Updated: 2024/08/20 17:44:10 by ele-lean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import json
import time
import os
import monotonic
import getpass
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

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
    "ansleima", "jgrisoni", "hzwak", "apain", "jliot", "bcuda", "kdelanoe", "mung",
    "ggros", "mcardonn", "fvasset", "tprovost", "hgautier", "yadoui-d", "gpommere",
    "tcarle", "ygarnier", "garside", "vconrair", "mrivon", "hbarthel", "tbroguy",
    "mlouiset", "thebrard", "agohis", "mde-bias", "een-nass", "llocquet", "loduhame",
    "cle-berr", "amarti", "bvilly", "atakoui", "tenard"
]


print("Nombre d'élèves: " + str(len(prenoms)))

login = input("Login: ")
mdp = getpass.getpass('Mdp: ')
dl = int(input("Temps entre chaques requetes: "))
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
    print("Duree de l'operation: " + str(monotonic.monotonic() - a))

with open("scores.json", "w") as fichier:
    json.dump(scores_liste, fichier, indent=4)
with open("temps_presence.json", "w") as fichier:
    json.dump(temps_presence_liste, fichier, indent=4)

print("Scores reçus: " + str(len(scores)))
