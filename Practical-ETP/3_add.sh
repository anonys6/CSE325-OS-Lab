#!/bin/bash

echo "Enter first operand: "
read a

echo "Enter second operand: "
read b

c=`expr $a + $b`

echo "Sum is: $c"