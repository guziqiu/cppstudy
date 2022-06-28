/*************************************************************************
    > File Name: 9.gcd.c
    > Author: Apricity
    > Mail:  
    > Created Time: Thu 03 Dec 2020 07:23:41 PM CST
 ************************************************************************/

#include<stdio.h>
int gcd(int a, int b) {
//	if (b == 0) return a;
//	if (!b) return a;
//	return gcd(b, a % b);
	return (b ? gcd(b, a % b) : a);
}

int main(int argc,const char* argv[]){
	int a, b;
	while(~scanf("%d%d", &a, &b)) {
		printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
	}
	return 0;
}
