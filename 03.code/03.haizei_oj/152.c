/*************************************************************************
    > File Name: 152.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 05 Dec 2020 06:10:10 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc,const char* argv[]){
	int n;
	scanf("%d", &n);
	n = (n + 3) % 7;
	switch(n) {
		case 1:
			printf("Monday\n");
			break;
		case 2:
			printf("Tuesday\n");
			break;
		case 3:
			printf("Wednesday\n");
			break;
		case 4:
			printf("Thursday\n");
			break;
		case 5:
			printf("Friday\n");
			break;
		case 6:
			printf("Saturday\n");
			break;
		default:
			printf("Sunday\n");
			break;
	}
	return 0;
}
