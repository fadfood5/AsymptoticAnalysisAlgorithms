#!/bin/bash

declare -a arr1=(1000, 10000, 100000, 100000, 500000, 1000000, 10000000, 100000000, 1000000000)
declare -a arr2=("s" "i" "q")
declare -a arr3=("s" "r" "c")


for i in "${arr1[@]}"
do
	for j in "${arr2[@]}"
	do
		for k in "${arr3[@]}"
		do
			./a.out $j $i $k
		done
	done
done