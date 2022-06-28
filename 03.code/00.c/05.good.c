/*************************************************************************
    > File Name: good.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 28 Nov 2020 02:38:36 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc,const char* argv[]){
	int n;
	while(~scanf("%d", &n)){
	if (!n) {
		printf("FOOLISH\n");
	} else if (n < 60){
		printf("FALL\n");
	} else if (n < 75){
		printf("MEDIUM\n");
	} else {
		printf("GOOD\n");
	}
	n == 0?(printf("FOOLISH1\n")):(n < 60?(printf("FALL1\n")):( n < 75?(printf("MEDIUM\n")):(printf("GOOD\n")) ));
	}



	return 0;
}
