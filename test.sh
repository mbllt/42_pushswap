#!/bin/bash

TMP='.tmp'
PLUS=1
START=1015
let END=START+3
COUNTER=0
while [  $COUNTER -lt 20 ]; do
	NBR=`ruby -e "puts ($START..$END).to_a.shuffle.join(' ')"`
	# echo "${NBR}"
	./push_swap $NBR > $TMP
	if [[ $? -eq -1 ]]; then
		echo ----------- FAIL code -1 -----------
		echo "${NBR}"
		exit
	fi
	RESULT=$(./checker $NBR < $TMP)
	echo "${RESULT}"
	if [[ $RESULT != "OK" ]]; then
		echo ----------- FAIL checker -----------
		echo "${NBR}"
		exit
	fi
	echo ---------------- $COUNTER . OK ----------------
	let START=START+PLUS
	let END=START+PLUS
	let COUNTER=COUNTER+1
done