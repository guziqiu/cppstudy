/*************************************************************************
    > File Name: 11.prime.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 05 Dec 2020 07:28:24 PM CST
 ************************************************************************/

#include<stdio.h>
#define max_n 100

int prime[max_n + 5] = {0};
void init() {
	for (int i = 2; i <= max_n; i++) {
		if (prime[i]) continue;
		prime[++prime[0]] = i;
		for (int j = i * i; j <= max_n; j += i) {
				prime[j] = 1;
		}
	}
}
int main(int argc,const char* argv[]){
	init();
	for (int i = 2; i <= prime[0]; i++){
		printf("%d\n", prime[i]);
	}
	return 0;
}
