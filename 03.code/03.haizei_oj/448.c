#include <stdio.h>
#define max_n 100
int main()
{
    int n;
    scanf("%d", &n);
    int num[max_n + 5];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    int a;
    scanf("%d", &a);
    for (int i = 0; i < n; i++) {
        if(num[i] == a) {
            printf("%d\n", ++i);
            break;
        }
    }





    return 0;
}

