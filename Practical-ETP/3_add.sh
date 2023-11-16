#!/bin/bash

echo "Enter first operand: "
read a

echo "Enter second operand: "
read b

c=`expr $a + $b`

echo "Sum is: $c"

if [ $c -gt 10 ]
then
    echo "Sum is greater than 10"
else
    echo "Sum is less than 10"
fi