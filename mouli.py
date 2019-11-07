#!/bin/python3

import sys
import os
import time
import filecmp
import subprocess

def test_passed(filename):
	print("\033[1;34m" + filename + " : OK\033[37m")
	print(end="\033[32m")
	os.system("/usr/bin/time -q -f \"\n[TIME] %E\n[CPU]  %P\n[CODE] %x\" ./bsq " + filename + " > /dev/null")
	print("\033[37m")

def main():
	TOTAL = 0
	PASSED = 0
	TIMEOUT = 0
	FAILED = 0
	COVERAGE = 0
	TIME = 0
	if not (os.path.isdir("./mouli_maps") and os.path.isdir("./mouli_maps_solved") and os.path.isdir("./mouli_maps_solved/mouli_maps")):
		exit(1)
	if not (os.path.isfile("./bsq") and os.access("./bsq", os.X_OK)):
		os.system("make --silent && make clean --silent")
	for path, dirs, files in os.walk('mouli_maps'):
		for index, filename in enumerate(files):
			print("[" + str(index + 1) + "] \033[1;34m" + filename, end="\033[0m:")
			delay = time.time()
			code = os.system("./bsq " + path + "/" + filename + " > ./.tmp")
			delay = time.time() - delay
			TIME += delay
			print(" in\033[1;33m", "{:.4f}".format(delay), "\033[0mseconds")
			print(end="\033[1mSTATUS\033[0m : ")
			if filecmp.cmp("./.tmp", "./mouli_maps_solved/" + path + "/" + filename):
				if delay > 5:
					print("\033[1;37;43m TIMEOUT \033[0m")
					TIMEOUT += 1
				else:
					print("\033[1;37;42m PASSED \033[0m")
					PASSED += 1
			else:
				print("\033[1;37;41m ERROR \033[0m")
			print()
			TOTAL += 1
	if TOTAL > 0 :
		os.system("rm ./.tmp")
		FAILED = TOTAL - PASSED - TIMEOUT
		COVERAGE = PASSED / TOTAL * 100
		print("\nTOTAL TIME : \033[1;33m{:.4f}\033[0m seconds".format(TIME))
		print("\033[37m[\033[1;34mtotal : " + str(TOTAL) + "\033[37m] " + ("[\033[32mpassed : " + str(PASSED) + "\033[37m] " if PASSED > 0 else "") + ("[\033[33mtimed out : " + str(TIMEOUT) + "\033[37m] " if TIMEOUT > 0 else "") + ("[\033[31mfailed : " + str(FAILED) + "\033[37m]" if FAILED > 0 else "") + "  >> " + "{:.2f} %".format(COVERAGE))
	else:
		print("No tests")

if __name__ == "__main__":
	main()