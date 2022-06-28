/*************************************************************************
    > File Name: 10.array.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 05 Dec 2020 06:33:53 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc,const char* argv[]){
	int arry[100] = {0};
	for (int i = 1; i <= 100; i++) {
		printf("array[%d] = %d\n", i - 1, arry[i - 1]);
	}
	return 0;
}
