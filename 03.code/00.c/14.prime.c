/*************************************************************************
    > File Name: 14.prime.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 05 Dec 2020 08:37:26 PM CST
 ************************************************************************/

#include<stdio.h>
#define max_n 10000

int prime[max_n + 5];

void init() {
	for (int i = 2; i <= max_n; i++) {
		if (!prime[i]) prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0]; j++) {
			if (prime[j] * i > max_n) break;
			prime[prime[j] * i] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

int main(int argc,const char* argv[]){
    init();
	for (int i = 1; i <= prime[0]; i++) {
		printf("%d\n", prime[i]);
	}
	printf("prime[0] = %d\n", prime[0]);
	return 0;
}
