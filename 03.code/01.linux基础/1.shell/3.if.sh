#########################################################################
# File Name: 3.if.sh
# Author: 古子秋
# mail: 
# Created Time: Sun 29 Nov 2020 06:17:53 PM CST
#########################################################################
#!/bin/bash
read a
if [[ ${a} -gt 10 ]];then
	echo "$a > 10"
elif [[ ${a} -eq 10 ]];then
	echo "$a = 10"
else
	echo "$a < 10"
fi
