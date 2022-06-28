/*************************************************************************
    > File Name: test2.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 28 Nov 2020 07:14:26 PM CST
 ************************************************************************/

#include<stdio.h>

int rev_num(int n, int base){
	if (n < 0) return 0;
	int x = n;
	int temp = 0;
	while (x){
		temp = temp * base + x % base;
		x /= base;
	}
	return temp == n;
}
int main(){
	
	int n;
	scanf("%d", &n);
	printf("%s\n", rev_num(n, 10) ? "YES" : "NO");
	int x = n;
	int digit = 0;
	 do{
	 x /= 10;
	 digit += 1;
	}while(x);
	printf("%d has %d digits !\n",n , digit);
	return 0;
}
