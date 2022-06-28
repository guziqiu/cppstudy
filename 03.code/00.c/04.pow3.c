/*************************************************************************
    > File Name: pow.c
    > Author: Apricity
    > Mail:  
    > Created Time: Thu 26 Nov 2020 07:30:44 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main(int argc,const char* argv[]){
	double n;
	scanf("%lf", &n);
	printf("%f", pow(n, 1.0 / 3));
	return 0;
}
