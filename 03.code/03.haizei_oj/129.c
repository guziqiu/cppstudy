/*************************************************************************
    > File Name: 129.c
    > Author: Apricity
    > Mail:  
    > Created Time: Fri 04 Dec 2020 06:06:26 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc,const char* argv[]){
     int n;
	 int s[10000];
	 int a = 1000;
	 scanf("%d", &n);
	 for (int i = 1; i <= n; i++){
		scanf("%d", &s[i]);
		if (a > s[i]) a = s[i];
	 }
	 printf("%d\n", a);


	return 0;
}
