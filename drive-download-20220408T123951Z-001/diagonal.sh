#!/bin/bash
for (( i = 1; i<= $2; i++ ))
do
	for (( j = 1; j< $i; j++ ))
	do 
		echo -n " "
	done
	echo "$1"
done
echo ""
