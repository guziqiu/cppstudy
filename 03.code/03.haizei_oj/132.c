/*************************************************************************
    > File Name: 132.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 05 Dec 2020 04:22:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main(int argc,const char* argv[]){
	int n;
	long long num = 1;
	scanf("%d", &n);
	int temp;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		num *= temp;
	}
	printf("%lld\n", num);
	return 0;
}
