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
	import os
	import sys
	import subprocess
	import json
	import dropbox
	from datetime import datetime

	ACCESS_TOKEN = 'sl.B7VnfLsB9sZ53ypETHnfb7OXcIK4nKRYinyNqWT0loehWCelcxDwmuuaQPYEeDeFXxXt4BSv25m_Lx8eghQsEvrI9m54SJRK2DI6b3akdcAI6LkvZ-gIiy3rtyxFfYwmdwYqViP1c9oMDavWnkjvjtg'
	dbx = dropbox.Dropbox(ACCESS_TOKEN)
	dropbox_file_path = '/scores.json'

	_, res = dbx.files_download(dropbox_file_path)
	scores_liste = json.loads(res.content.decode('utf-8'))

	a = 0
	min_index = 0
	def col(i):
		if i < 11:
			return "\033[0;95m"
		elif i < 51:
			return "\033[0;92m"
		elif i < 76:
			return "\033[0;96m"
		else:
			return "\033[0;91m"

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
	print("""\033[0;93m
                                   ___---___
                             ___---___---___---___
                       ___---___---    *    ---___---___
                 ___---___---    _   _    ___    ---___---___
           ___---___---         | | | |  (_  |         ---___---___
     ___---___---               `.__  |   / /_               ---___---___
__---___---_________________________|_|__|____|____________________---___---__
==============================================================================
 ||||           Leaderboard for the july piscine of 42 Le Havre           ||||
 |---------------------------------------------------------------------------|
 |___-----___-----------------------------------------------------___-----___|
 / _ \===/ _ \                                                   / _ \===/ _ \\
 \__/=====\__/                     __________                    \__/=====\__/
    |||||||                        |\033[0;33m""" + (scores_liste[0][0] + " " * (8 - len(scores_liste[0][0]))) + """\033[0;93m|                       |||||||
    |||||||        \033[0;90m__________\033[0;93m      |   🥇   |\033[0;93m                       |||||||
    |||||||        \033[0;90m|""" + (scores_liste[1][0] + " " * (8 - len(scores_liste[1][0]))) + """|\033[0;93m      \  """ + str(scores_liste[0][1]) + """  /\033[0;93m                       |||||||
    |||||||        \033[0;90m|   🥈   |\033[0;93m       |      |\033[0;93m       \033[0;94m__________ \033[0;93m      |||||||
    |||||||        \033[0;90m\  """ + str(scores_liste[1][1]) + """  /       \033[0;93m|      |\033[0;93m       \033[0;94m|""" + scores_liste[2][0] + """|\033[0;93m       |||||||
    |||||||         \033[0;90m|      |\033[0;93m        |      |\033[0;93m       \033[0;94m|   🥉   |\033[0;93m       |||||||
    |||||||         \033[0;90m|      |\033[0;93m        |      |\033[0;93m       \033[0;94m|  """ + str(scores_liste[2][1]) + """  |\033[0;93m       |||||||
    |||||||         \033[0;90m|000110|\033[0;93m        |101010|\033[0;93m       \033[0;94m\ 001001 /\033[0;93m       |||||||
    (oOoOo)         \033[0;90m(oOooOo)\033[0;93m        (oOooOo)\033[0;93m       \033[0;94m (oOooOo)\033[0;93m        (oOoOo)
    J%%%%%L         \033[0;90mJ%%%%%%L\033[0;93m        J%%%%%%L\033[0;93m       \033[0;94m J%%%%%%L\033[0;93m        J%%%%%L
   ZZZZZZZZZ       \033[0;90mZZZZZZZZZZ\033[0;93m      ZZZZZZZZZZ\033[0;93m      \033[0;94mZZZZZZZZZZ\033[0;93m      ZZZZZZZZZ
===============================================================================
  ===========================================================================
  |___-----___-----___-----___---------------------___-----___-----___-----___|
  / _ \===/ _ \   / _ \===/ _ \                   / _ \===/ _ \   / _ \===/ _ \\
  \__/=====\__/   \__/=====\__/                   \__/=====\__/   \__/=====\__/""")
	for i  in range(3, len(scores_liste)):
		print("""\033[0;93m     |||||||         |||||||    """ + col(i) + (str((i)) + ":" + " " * (2 - len(str(i)))) + " " + (scores_liste[i][0] + " " * (8 - len(scores_liste[i][0]))) + "  " + str(scores_liste[i][1]) + (" " * (7 - len(str(scores_liste[i][1])))) + """\033[0;93m|||||||         |||||||""")
	
	metadata = dbx.files_get_metadata(dropbox_file_path)
	modification_time = metadata.client_modified
	print("""\033[0;93m     |||||||         |||||||     \033[0;34mLast data update\033[0;93m    |||||||         |||||||""")
	print("""\033[0;93m     |||||||         |||||||   \033[0;34m""" + str(modification_time) + """\033[0;93m   |||||||         |||||||""")


	print(""" ===============================================================================
   |_________________________________________________________________________|
  |___________________________________________________________________________|
 |_____________________________________________________________________________|\033[0;0m""")
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
		"pathlib",
		"datetime"
	]

	for module in required_modules:
		try:
			__import__(module)
		except ImportError:
			print(f"Module {module} not found, installing...")
			install(module)
		else:
			print(f"Module {module} already installed.")
	print("\033[0;0m")