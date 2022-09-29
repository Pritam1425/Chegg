#!/bin/bash
for (( i = 1; i<= $2; i++ ))
do
	for (( j = $i; j< $2; j++ ))
	do 
		echo -n " "
	done
	echo "$1"
done
echo ""
