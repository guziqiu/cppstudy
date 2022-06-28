/*************************************************************************
    > File Name: 134.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 05 Dec 2020 05:52:21 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc,const char* argv[]){
    int a, b;
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; i++){
		if (i % 11) continue;
		printf("%d", i);
		if(i != b) printf(" ");
	}
	return 0;
}
