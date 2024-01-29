#!/bin/bash

echo "Enter upper limit"
read num
i=1
while [ $i -le $num ]
do
	count=0
	for((j=1; j<=i; j++))
	do
		if [ `expr $i % $j` -eq 0 ]
		then
			count=`expr $count + 1`
		fi
	done
	if [ $count -eq 2 ]
	then
		echo $i
	fi
	i=`expr $i + 1`
done