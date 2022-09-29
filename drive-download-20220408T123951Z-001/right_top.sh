#!/bin/bash
for (( i = 1; i<= $2; i++ ))
do
	for (( j = 1; j< $i; j++ ))
	do 
		echo -n " "
	done
	for (( j = $i; j<= $2; j++ ))
	do 
		echo -n "$1"
	done
	echo ""
done
echo ""
