#!/bin/bash

read num
declare -a prime
temp=0
temp1=0
function init_prime() {
    local end=1000
    local i=0
    for (( i=2; i <= 1000; i++ ));do
        for (( j=$[ 2 * ${i} ]; j <= 1000; j+=1 ));do
            prime[$[j]]=1
          #  temp=$[ ${temp} + 1 ]
           # if [[ $temp == j  ]];then
             #   break;
           # fi
        done
    done
}
init_prime 
temp=0
for (( i=0; i<=100; i++ ));do
    if [[ $[prime[$i]]x == x ]];then
       # temp=$[ ${temp} + 1  ]
        #if [[ $temp == j  ]];then
         echo ${prime[$i]}
           # break
        #fi
    fi
done
#echo ${prime[$i]}
echo "end"


