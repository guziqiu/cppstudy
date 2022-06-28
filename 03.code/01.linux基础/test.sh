#!/bin/bash
read L
read M

temp=0
left=L
right=L

for (( i=1; i <= M; i++ ));do
     read a
     read b
     if [[ $a -gt $left ]];then
     	if [[ $a -lt $right ]];then
    		 if [[ $a -lt $left ]];then
     			$left=$a
     		 fi
     	fi
     else
     	$left=0
     fi
     
     if [[ $b -gt $left ]];then
     	if [[ $b -lt $right ]];then
    		 if [[ $b -gt $right ]];then
     			$right=$b
     		 fi
     	fi
     else
     	$right=$L
     fi
     
done
temp=$[ $right - $left ]
temp=$[ $L - $temp ]
     
echo $temp
echo "asd"    
     
