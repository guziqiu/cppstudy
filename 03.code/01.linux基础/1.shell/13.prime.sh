#########################################################################
# File Name: 13.prime.sh
# Author: 古子秋
# mail: 
# Created Time: Fri 04 Dec 2020 10:43:39 AM CST
#########################################################################
#!/bin/bash
if [[ $# -ne 2 ]];then
	echo "error"
	exit
fi

start=$1
end=$2

declare -a prime

function init_prime() {
	local end=$1
	local i
	prime[1]=1
	for (( i=2; i <= ${end}; i++ ));do
		for (( j=$[ 2 * ${i} ]; j <= ${end}; j+=i ));do
			prime[${j}]=1	
		done
	done
}

init_prime ${end}


for (( i=${start}; i<=${end}; i++ ));do
	if [[ ${prime[$i]}x == x ]];then
		sum=$[ ${sum} + ${i} ]
	fi
done

echo ${sum}


