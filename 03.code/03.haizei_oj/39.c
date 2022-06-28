/*************************************************************************
    > File Name: 39.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 28 Nov 2020 05:58:41 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc,const char* argv[]){
	int begin;
	int n;
	scanf("%d%d", &begin, &n);

	(begin % 2 == 0) ? 1:(begin += 1);
	if(begin < 0){
		begin = 0;
	}

	int i = 0;
	int j;
	for (j = begin; i < n;j++){
		if (j % 2 == 0 ) {
			printf("%d\n", j);
			++i;
		}
	}
	return 0;
}
