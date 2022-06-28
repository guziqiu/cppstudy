#########################################################################
# File Name: 11.sprime.sh
# Author: 古子秋
# mail: 
# Created Time: Sun 29 Nov 2020 08:40:31 PM CST
#########################################################################
#!/bin/bash
if [[ $# -ne 2 ]];then
	echo "ERROR"
	exit
fi



start=$1
end=$2
declare -a Prime

function init_prime() {
	local end=$1
	local i
	Prime[1]=1
	for (( i=2; i<=${end}; i++ ));do
		for (( j=$[ 2 * ${i} ]; j<=${end}; j+=i ));do
			prime[${j}]=1
		done
	done
}
init_prime ${end}
echo ${Prime[*]}
for (( i=${start}; i<=${end}; i++ ));do
	if [[ ${Prime[$i]}x == x ]];then
		echo ${i}
	fi


