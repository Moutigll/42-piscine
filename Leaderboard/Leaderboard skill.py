# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Leaderboard skill.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 16:58:45 by ele-lean          #+#    #+#              #
#    Updated: 2024/08/20 17:30:31 by ele-lean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import json

temp = []

# Chargement des scores depuis le fichier JSON
with open("scores.json", "r") as fichier_scores:
    scores_liste = json.load(fichier_scores)

# Tri des scores par ordre décroissant
for i in range(len(scores_liste)):
    min_index = i
    for a in range(i + 1, len(scores_liste)):
        if scores_liste[min_index][1] < scores_liste[a][1]:
            min_index = a
    if min_index != i:
        temp = scores_liste[i]
        scores_liste[i] = scores_liste[min_index]
        scores_liste[min_index] = temp

# Affichage des scores triés
for i in range(len(scores_liste)):
    print(f"{i + 1} {scores_liste[i][0]}: {scores_liste[i][1]} pts")