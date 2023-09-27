#!/bin/bash
sum=0
num=0
i=1
while [ $i -lt 11 ]
do
	sum=`expr $sum + $i`
	i=`expr $i + 1`
done

avg=`expr $sum / 10`
echo "Average: " $avg 
