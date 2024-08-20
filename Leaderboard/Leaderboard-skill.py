# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Leaderboard-skill.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 16:58:45 by ele-lean          #+#    #+#              #
#    Updated: 2024/08/20 19:29:24 by ele-lean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

try:
	import json

	a = 0
	min_index = 0
	temp = []

	with open("/sgoinfre/goinfre/Perso/ele-lean/Leaderboard/scores.json", "r") as fichier_scores:
		scores_liste = json.load(fichier_scores)

	for i in range(len(scores_liste)):
		a = i
		min_index = i
		while a < len(scores_liste):
			if scores_liste[min_index][1] < scores_liste[a][1]:
				min_index = a
			a+=1
		if min_index != i:
				temp = scores_liste[i]
				scores_liste[i] = scores_liste[min_index]
				scores_liste[min_index] = temp
	for i in range(len(scores_liste)):
		print(str((i + 1)) + " " + scores_liste[i][0] + ": " + str(scores_liste[i][1]) + "pts")
except:
	print("Multiple modules are required to run this script\ntry running these commands before running the script again\n\n\tpip install monotonic\n\tpip install selenium")