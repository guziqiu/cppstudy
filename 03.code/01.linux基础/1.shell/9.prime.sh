#########################################################################
# File Name: 9.prime.sh
# Author: 古子秋
# mail: 
# Created Time: Sun 29 Nov 2020 07:25:07 PM CST
#########################################################################
#!/bin/bash

function Usage(){
	echo "Usage : $0 start_num end_num"
	exit
}
function is_prime(){
	num=$1
	local i
	for (( i=2; i<${num}; i++ ));do
		if [[ $[ ${num} % $i ] -eq 0 ]];then
			return 1
		fi
	done
	return 0
}

if [[ $# -ne 2 ]];then
	Usage
fi



start=$1
end=$2

for (( i=${start}; i<=${end}; i++ ));do
	is_prime $i
	if [[ $? -eq 0 ]];then
		set +x
		sum=$[ ${sum} + $i ]
		set -x
	fi
done

echo ${sum}

