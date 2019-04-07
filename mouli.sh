#!/bin/bash

TOTAL=0
PASSED=0
FAILED=0
COVERAGE=0

test_passed () {
	echo -e "\e[1;34m"$filename : OK"\e[37m"
	echo -e -n "\e[32m"
	/usr/bin/time -q -f "\n[TIME] %E\n[CPU]  %P\n[EXIT] %x" ./bsq $filename > /dev/null
	echo -e "\e[37m"
	let "PASSED++"
}

if [ ! -x bsq ]; then
	make --silent
	make clean --silent
fi

for filename in mouli_maps/*; do
	./bsq $filename > .tmp
	echo -e "\e[1;31m"
	cmp .tmp mouli_maps_solved/$filename && test_passed
	let "TOTAL++"
done
rm .tmp
let "FAILED=TOTAL-PASSED"
let "COVERAGE=PASSED/TOTAL*100"
echo -e "\e[37m"
echo -e -n ["\e[1;34m"total : $TOTAL"\e[37m"] ["\e[32m"passed : $PASSED"\e[37m"] ["\e[31m"failed : $FAILED"\e[37m"]  ">> "
awk "BEGIN {printf \"%.2f %%\n\", $PASSED / $TOTAL * 100}"
echo
