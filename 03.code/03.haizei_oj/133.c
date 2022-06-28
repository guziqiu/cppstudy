/*************************************************************************
    > File Name: 133.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sun 06 Dec 2020 11:42:08 AM CST
 ************************************************************************/

#include<stdio.h>
#define max_n 40
int main(int argc,const char* argv[]){
    int n = max_n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for ( int j = i; j <= n; j++) {
			if(i != j) printf("\t");
			printf("%d*%d=%d", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}
