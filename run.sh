#!/bin/bash

declare -a arr1=(10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000, 500000, 1000000, 500000, 1000000, 10000000, 100000000, 1000000000)
declare -a arr2=("s" "i" "q")
declare -a arr3=(0, 1, 2)


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