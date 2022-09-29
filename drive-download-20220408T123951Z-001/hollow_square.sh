#!/bin/bash
for (( i = 1; i<= $2; i++ ))
do
	echo -n "$1"
done
echo ""
for (( i = 1; i<= $2-2; i++ ))
do
	echo -n "$1"
	for (( j = 1; j<= $2-2; j++ ))
	do
		echo -n " "
	done
	echo "$1"
done
for (( i = 1; i<= $2; i++ ))
do
	echo -n "$1"
done
echo ""
