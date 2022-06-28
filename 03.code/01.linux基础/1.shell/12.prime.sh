#########################################################################
# File Name: 12.prime.sh
# Author: 古子秋
# mail: 
# Created Time: Fri 04 Dec 2020 09:24:13 AM CST
#########################################################################
#!/bin/bash
start=$1
end=$2
function Usage(){
	echo "Usage : $0 start_num end_num"
	exit
} 
function is_prime(){
	num=$1
	local i
	for (( i=2; i<${num}; i++ ));do
		if [[ $[ ${num} % ${i} ] -eq 0 ]];then
				return 1
		fi
	done
	return 0 
}
if [[ $# -ne 2 ]];then
	Usage
fi
for (( i=${start}; i<=${end}; i++ ));do
	is_prime ${i}
	if [[ $? -eq 0 ]];then
		sum=$[ ${sum} + $i ]
	fi
done

echo $sum










