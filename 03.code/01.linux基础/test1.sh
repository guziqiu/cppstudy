#!/bin/bash

read n
#n=3
declare -a prime
start=2
end=10000
function init_prime() {
    local end=$1
    local i 
 #   prime[1] = 1
    for (( i=2; i <= ${end}; i++ ));do
         for (( j=$[ 2*$[i] ]; j <= $[end]; j+=i));do
        	prime[$[j]]=1
        done
    done
}

init_prime ${end}
num=0
sum=0
for (( i=${start}; num < ${n}; i++));do
     if [[ ${prime[$i]}x == x ]];then
     	sum=$[ ${sum} + ${i} ]
        num=$[ ${num} + 1 ]
     	echo ${num} ${i}
     fi
done
     echo ${sum}
