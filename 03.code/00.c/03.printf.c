/*************************************************************************
    > File Name: 3.printf.c
    > Author: Apricity
    > Mail: 1944194030@qq.com 
    > Created Time: Tue 24 Nov 2020 08:36:52 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc,const char* argv[]){
	int n;
	char str[1000] = {0};
# if 0
	//标准输入
	scanf("%d", &n);//stdin
	//标准输出
	printf("%d\n", n);//stdout stderr
# endif
	sprintf(str, "%d.%d.%d.%d", 192, 168, 1, 1);
	printf("str = %s\n", str);
	FILE *fout = fopen("output", "w");

	fprintf(stdout, "stdout = %s\n", str);
	fprintf(stderr, "stdoerr = %s", str);
	return 0;
}
