# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 19:47:53 by ele-lean          #+#    #+#              #
#    Updated: 2024/08/19 22:15:23 by ele-lean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import json
import time
import monotonic
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
a = monotonic.monotonic()
# Liste des prénoms
prenoms = [
    "ele-lean", "almeddah", "lchauvet", "malevieu", "ladurand", "cpoulain", "tobesnar",
    "edetoh", "throbert", "lnassar", "jcheron", "cabraham", "vseyidov", "tle-goff",
    "aberenge", "releroy", "hdelacou", "lsellier", "nlecreux", "cfleuret", "mavander",
    "lvan-bre", "niclambe", "jbastard", "abidaux", "ljacq", "ghoyaux", "huyanan",
    "adcisse", "mduvey", "tgoudman", "abosc", "aperceva", "lgrisel", "alegrix",
    "jabertin", "ameduboi", "tolivaud", "emaillet", "mpelleri", "ngaudoui", "dbaciu",
    "calleaum", "rbardet-", "tharrel", "hdruel", "aboutry", "jeetienn", "etaquet",
    "tliberse", "guphilip", "afolliot", "fkurti", "plerick", "minhpham", "pilot-de",
    "mgarsaul", "mpapin", "mgendrot", "clephal", "sbenamar", "pthuilli", "ogsimsek",
    "tlize", "artgirar", "lleborgn", "luguo", "maiba", "fbriault", "mtatar", "salwong",
    "azhao", "mkreko", "lplottin", "isehim", "bperrot", "spicque", "rdelepin",
    "abensala", "jhatting", "matgabri", "gdefrace", "abuty", "ngilles", "jnicolle",
    "jtannier", "qgutmann", "taubry", "mflandri", "rbouchou", "ansleima", "jgrisoni",
    "hzwak", "apain", "jliot", "bcuda", "kdelanoe", "mung", "ggros", "mcardonn",
    "fvasset", "tprovost", "hgautier", "yadoui-d", "gpommere", "tcarle", "ygarnier",
    "garside", "vconrair", "mrivon", "hbarthel", "tbroguy", "mlouiset", "thebrard",
    "davlelie", "agohis", "mde-bias", "een-nass", "llocquet", "loduhame", "cle-berr",
    "amarti", "bvilly", "atakoui", "tenard"
]

print("Nombre d'élèves: " + str(len(prenoms)))

# Login et mot de passe
login = ""
mdp = ""

# Initialiser le pilote Chrome
driver = webdriver.Chrome()

# Liste pour stocker les scores
scores = []

try:
    # Ouvrir la page d'authentification de 42
    driver.get("https://auth.42.fr/auth/realms/students-42/protocol/openid-connect/auth?client_id=intra")

    # Localiser les champs de saisie du nom d'utilisateur et du mot de passe
    username = driver.find_element(By.ID, "username")
    password = driver.find_element(By.ID, "password")

    # Saisir les informations de connexion
    username.send_keys(login)
    password.send_keys(mdp)

    # Localiser et cliquer sur le bouton de connexion
    submit_button = driver.find_element(By.ID, "kc-login")
    submit_button.click()

    # Attendre que la connexion soit réussie et que la page d'accueil soit chargée
    WebDriverWait(driver, 10).until(
        EC.url_contains("https://profile.intra.42.fr")
    )

    # Itérer à travers la liste des prénoms pour extraire les scores
    for index, prenom in enumerate(prenoms):
        # Accéder à la page des compétences de l'utilisateur
        driver.get(f"https://profile.intra.42.fr/users/{prenom}/skills")

        # Attendre que la page soit complètement chargée
        WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.TAG_NAME, "pre"))
        )

        # Récupérer le texte de la page
        page_content = driver.find_element(By.TAG_NAME, "pre").text

        # Charger le contenu JSON
        try:
            skills = json.loads(page_content)
        except json.JSONDecodeError:
            print(f"Erreur de décodage JSON pour {prenom}")
            scores.append(0)  # Ajouter 0 ou gérer autrement
            continue

        # Calculer le score
        total_percent = sum(skill.get("percent", 0) for skill in skills)
        total_level = sum(skill.get("lvl", 0) * 100 for skill in skills)
        score = total_percent + total_level
        scores.append(score)

        print(f"Score pour {prenom}: {score}")

        # Ajouter un délai entre les requêtes pour éviter de surcharger le serveur
        time.sleep(0.0)  # Délai de 2 secondes

finally:
    
    input("Appuyez sur Entrée pour fermer le navigateur...")

    # Fermer le navigateur
    driver.quit()

# Afficher les scores
print("Scores des élèves :")
for prenom, score in zip(prenoms, scores):
    print(f"{prenom}: {score}")
print("Temps total: " + str(monotonic.monotonic() - a))
print("Scores recus: " + str(len(scores)))