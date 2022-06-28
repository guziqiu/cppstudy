/*************************************************************************
    > File Name: 1.阶乘.c
    > Author: Apricity
    > Mail:  
    > Created Time: Tue 01 Dec 2020 07:22:02 PM CST
 ************************************************************************/

#include<stdio.h>

int fac(int i){
#if 1
	if(i > 1){
		return i * fac(i - 1);
	}
	return 1;
#endif
//	i > 1 ? (return i * fac(i - 1)):(return 1);
}


int main(int argc,const char* argv[]){
	int n;
	scanf("%d", &n);
	printf("%d\n", fac(n));
	return 0;
}
