#!/bin/bash

read -p " enter num1: " startnum
read -p " enter num2: " endnum
read -p " enter num3: " oddeven

init=$(($startnum%2))
init2=$(($oddeven%2))

if [ $init -ne $init2 ]
then
startnum=$startnum+1
fi

for ((i=$startnum;i<$endnum;i=i+2))
do
echo $i
done
