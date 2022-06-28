/*************************************************************************
    > File Name: switch1.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 28 Nov 2020 03:19:45 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc,const char* argv[]){
	int n;
	scanf("%d", &n);
	switch(n){
		case 1: 
			printf("one ");
		case 2:
			printf("two ");
		case 3:
			printf("three\n");
			break;
		default:
			printf("error\n");
			break;
	}
	return 0;
}
