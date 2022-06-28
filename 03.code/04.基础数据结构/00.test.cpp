#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[3]={1,3,5};

     int *p = (int *)malloc(sizeof(int) * 10);
     *p = a[0];
     *(p+1) = 5;
     *(p + 2) = 9;
     
     //free(p);

     printf("*(p + 1) = %d,\np = %p\n\n",*(p+1), p);
     free(p);
     printf("p = %p\n", p);
     printf("*p = %d\n\n", *p);


    return 0;
}
