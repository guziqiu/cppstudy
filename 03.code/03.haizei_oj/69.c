/*************************************************************************
    > File Name: 69.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 28 Nov 2020 08:03:02 PM CST
 ************************************************************************/

#include<stdio.h>

int check(int y, int m, int d){
	if (m <= 0 || m > 12 || d <= 0) return 0;
	int mouth[13] = {0, 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};
	if ((y % 4 ==0 && y %100) || y % 400 == 0) mouth[2] += 1;
	return d<= mouth[m];
}

int main(int argc,const char* argv[]){
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);
	printf("%s\n", check(y, m, d) ?  "YES" : "NO");
	return 0;
}
