/*************************************************************************
    > File Name: 3.c
    > Author: Apricity
    > Mail: 1944194030@qq.com 
    > Created Time: Fri 20 Nov 2020 06:53:44 PM CST
 ************************************************************************/

#include<stdio.h>
#define max_n 10

int  prime[max_n + 5];


void init(){
      for (int i = 2; i <= max_n; i++){
		  if (!prime[i]) prime[++prime[0]] = i;
		  for (int j = 1; j <= prime[0]; j++){
			  if(prime[j]  * i > max_n) break;
			  prime[prime[j] * i] = 1;
			  if (i% prime[j] == 0) break;
		  }
	  }
	return ;
}
int main(){

	init();
	for(int i = 1; i <= prime[0]; i++){
		printf("%d\n",prime[i]);
	}
}
