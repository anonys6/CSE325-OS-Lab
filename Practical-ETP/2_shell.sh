#!/bin/bash

echo "Enter first operand: "
read a
echo "Enter second operand: "
read b

echo "Operation: "
echo "1) Addition"
echo "2) Subtractoin"
echo "3) Multiplication"
echo "4) Division"
echo "5) Modulus"

read o

case $o in
1) echo "Addition: " `expr $a + $b` ;;
2) echo "Subtraction: " `expr $a - $b` ;;
3) echo "Multiplication: " `expr $a \* $b` ;;
4) echo "Division: " `expr $a / $b` ;;
5) echo "Modulus: " `expr $a % $b` ;;
*) echo "Invalid operation" ;;
esac
