/*************************************************************************
    > File Name: 116.c
    > Author: Apricity
    > Mail:  
    > Created Time: Thu 03 Dec 2020 10:20:10 AM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int illegal(int a, int b, int c){
	if(a  + b   >= c )	return 1;
	return 0;
}

int check(int a, int b, int c) {
	int  temp;
	if (!illegal(a, b, c) || !illegal(a, c ,b) ||! illegal(b, c, a)) return 0;
	if (a > b) {
		temp = a;
		a = b;
		b = temp;
	} 
	if (a > c) {
		temp = a;
		a = c;
		c =temp;
	}
	if (b > c) {
		temp = b;
		b = c;
		c = temp;
	}
	if (a * a + b * b > c * c) return 1;
	if (a * a + b * b == c * c) return 2;
	if (a * a + b * b < c * c) return 3;



}


int main(int argc,const char* argv[]){
      
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	
	if(check (a, b, c) == 0) printf("illegal triangle\n");
	else if(check (a, b, c) == 1) printf("acute triangle\n");
	else if(check (a, b, c) == 2) printf("right triangle\n");
	else printf("obtuse triangle\n");


	return 0;
}
