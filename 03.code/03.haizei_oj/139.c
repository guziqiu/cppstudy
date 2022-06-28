/*************************************************************************
    > File Name: 139.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sun 06 Dec 2020 05:59:45 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc,const char* argv[]){
     int n;
    scanf("%d", &n);
    
	 for (int i = 1; i <= n ; i++) {
         for (int k = n - i; k > 0; k--) printf(" ");
         for(int j = 1; j <= 2 * i; j++) printf("A");
         printf("\n");
     }
    
     for (int i = n - 1; i >= 1; i--) {
         for (int k = n - i; k >  0; k--) printf(" ");
         for (int j = 2 * i; j >= 1; j--) printf("A");
         printf("\n");
     }

	return 0;
}
