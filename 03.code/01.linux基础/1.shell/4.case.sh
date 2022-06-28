#########################################################################
# File Name: 4.case.sh
# Author: 古子秋
# mail: 
# Created Time: Sun 29 Nov 2020 06:32:29 PM CST
#########################################################################
#!/bin/bash
read a
case $a in
	1)
		echo 1
		;;
	2)
		echo 2
		;;
	default)
		echo "not found"
		;;
esac
