#!/bin/bash

echo "To plot right-top triangle, press R"
echo "To plot diagonal, press D"
echo "To plot secondary diagonal, press S"
echo "To plot Hollow square, press H"
echo "To exit, press Q"

chmod +x right_top.sh
chmod +x diagonal.sh
chmod +x secondary_diagonal.sh
chmod +x hollow_square.sh

echo -n "Enter your option to plot pattern: "
read option

echo -n "Enter a symbol to be used to plot your pattern: "
read symbol

echo -n "Enter your pattern size: "
read size

while true
do
	if [ $option == "R" ]
	then 
		bash right_top.sh "$symbol" "$size"
	elif [ $option == "D" ]
	then
		bash diagonal.sh "$symbol" "$size"
	elif [ $option == "S" ]
	then
		bash secondary_diagonal.sh "$symbol" "$size"
	elif [ $option == "H" ]
	then
		bash hollow_square.sh "$symbol" "$size"
	elif [ $option == "Q" ]
	then
		break
	else
		echo "Unknown option entered ... !"
	fi

	echo -n "You want to plot another pattern? enter another option: "
	read option
done
