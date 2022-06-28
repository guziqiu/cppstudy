#include <stdio.h>

int rev_num(int num){
    int temp = 0;
    int num1 = num;
    while (num1) {
        temp = num1 % 10 + temp * 10;
        num1 /= 10;
    }
    
    return temp == num;
}
#define max_n 99999
int prime[max_n] = {0};
int primef (int num) {
    for (int i = 2; i < num; i++) {
        if(num % i == 0) return 0;
    }
    return 1;
}


int main()
{
    int a,b;
    scanf("%d%d", &a, &b);
    printf("rev_num ==> %d\n", rev_num(1111));
    int  j = 0;
    for (int i = a; i <= b; i++) {
        if(!rev_num(i)) continue;
         printf("%d\n", i);
        if(!primef(i)) continue;
        if(j != 0) printf(" ");
         printf("%d\n", i);
         j++;
    }
    return 0;
}

