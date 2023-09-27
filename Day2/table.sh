#!/bin/bash
echo "Enter number whose table you want:"
read num

echo "Table of $num"
i=1
while [ $i -ne 11 ]
do
	echo "$num * $i = " `expr $num \* $i`
	i=`expr $i + 1`
done
