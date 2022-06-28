/*************************************************************************
    > File Name: test2.c
    > Author: Apricity
    > Mail: 1944194030@qq.com 
    > Created Time: Tue 24 Nov 2020 07:28:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(int argc,const char* argv[]){

	char str[1000] = {0};
	int i;
	while(scanf("%[^\n]s",str) != EOF){
		getchar();
		printf("  has  %d digits!\n", printf("%s", str));
		printf("%s  has  %ld digits!\n", str, strlen(str));
	}
	return 0;
}
