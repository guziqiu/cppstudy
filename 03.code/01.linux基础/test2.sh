#!/bin/bash

 
read n
declare -a prime
end=10005
for (( i = 1; i <= ${n}; i++ ));do
    read prime[${i}]
done
sum=0
for (( i = 1; i <= ${n}; i++ ));do
    a=0
    b=0
    for (( j = 1; j <= ${n}; j++ ));do
        if [[ j -lt i && prime[${j}] -gt prime[${i}] ]];then
            let a=$[ ${a} + 1 ]
        fi
        if [[ j -gt i && prime[${j}] -gt prime[${i}] ]];then
            b=$[ ${b} + 1 ]
        fi
    done
    if [[ ${a} == ${b} ]];then
        sum=$[ ${sum} + 1 ]
        echo -e "==>${prime[$i]}\n"
    fi
done
echo "==>"
echo ${sum}


