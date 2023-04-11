#!/usr/bin/env zsh
echo "Enter a value"
read n
if [ $n -lt 10 ];
then
echo "It is a one digit number"
elif [ $n -gt 9 -a $n -lt 100 ];
then
echo "It is a two digit number"
else
echo "It is a number with more than two digits"
fi
