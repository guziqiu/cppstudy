/*************************************************************************
    > File Name: 127.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 05 Dec 2020 05:31:13 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc,const char* argv[]){
	int x;
	int n;
	scanf("%d%d", &x, &n);
	for (int i = 1; i <= n; i++){
		x = x * (1 + 0.06);
	}
	printf("%d", x);

	return 0;
}
