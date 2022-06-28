/*************************************************************************
    > File Name: test.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 28 Nov 2020 06:15:07 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(int argc,const char* argv[]){

    int i = 0;
    while (~scanf("%d", &i)) {
        if (i <= 0) printf("==> 0\n");
        else if (i <= 10) printf("==> 1\n");
        else if (i <= 20) printf("==> 2\n");
        else printf("......\n");
    }
    return 0;
    
    
    int sum = 0;
	for (int i = 0; i < 5; i++){
		if( i % 2 == 0){
			printf("%d ", i);
		}
		sum += (i & 1);
	}
	printf("\n%d\n", sum);



	return 0;
	//int n;
	//scanf("%d", &n);
	srand(time(0));
	for (int i = 0; i < 5; i++){
		int val = rand() % 100;
	//	if (i) printf(" ");
	//	i && printf(" ");
		i == 0 || printf(" ");
		printf("%d", val);
	}      
	printf("\n");
	return 0;
}
