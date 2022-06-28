#########################################################################
# File Name: 5.for.sh
# Author: 古子秋
# mail: 
# Created Time: Sun 29 Nov 2020 06:40:11 PM CST
#########################################################################
#!/bin/bash
for i in $@;do
	echo $i
done 


for ((i=1; i <= 100; i++));do
	echo $i
done
