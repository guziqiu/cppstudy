/*************************************************************************
    > File Name: 464.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 05 Dec 2020 04:45:14 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc,const char* argv[]){
	int a, b;
	scanf("%d%d", &a, &b);
	
	int num = 0;

	for (int i = a; i <= b; i++){
		if ((i % 4 == 0 && i % 400 != 0) || i % 400 == 0 ) num++;
	}
	printf("%d\n", num);


	return 0;
}
