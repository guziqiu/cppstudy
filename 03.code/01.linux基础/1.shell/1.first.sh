#########################################################################
# File Name: first.sh
# Author: 古子秋
# mail: 
# Created Time: Sun 29 Nov 2020 04:16:44 PM CST
#########################################################################
#!/bin/bash
echo "hello guziqiu!"


workdir=`pwd`
echo -e "In\033[31;32m] ${workdir} \033[0m"
echo "Programe Name : $0"
echo "arg1 : $1"

echo "arg2 : $2"
echo "arg6 : $6"
echo "arg3 : $3"
echo "arg4 : $4"
echo "arg5 : $5"
echo "\$@ : $@"
echo "\$* : $*"

