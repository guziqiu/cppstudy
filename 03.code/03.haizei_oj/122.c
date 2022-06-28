/*************************************************************************
    > File Name: 122.c
    > Author: Apricity
    > Mail:  
    > Created Time: Fri 04 Dec 2020 05:14:24 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc,const char* argv[]){
	int t;
	scanf("%d", &t);

	int h, m, s;
	int i = 0;
	h = t / 3600;

	m = t / 60 - h * 60; 
	
	s = t - h * 3600 - m * 60; 

	if(h == 12) i++;
	if(h > 12) h = h -12;

	if(!(h / 10)) printf("0%d:", h);
	else printf("%d:", h);

	if(!(m / 10)) printf("0%d:", m);
	else printf("%d:", m);

	if(!(s / 10)) printf("0%d ", s);
	else printf("%d ", s);


	if(i == 1) printf("midnoon\n");
	else printf("\n");
//	printf("%d:%d:%d", h, m, s);

	return 0;
}
