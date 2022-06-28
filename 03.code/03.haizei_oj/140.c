#include <stdio.h>

void init(int n){
    char a = 'A';
    for (int i = 1; i <= n; i++) {
        for (int k = n - i; k >= 1; k--) printf(" ");
        for (int j = 2 * i - 1 ; j >= 1 ; j--) printf("%c", a);
        printf("\n");
        a += 1;
    }   
    a--;
    for (int i = n - 1; i >= 1; i--) {
        a -= 1;
        for (int k = n - i; k > 0; k--) printf(" ");
        for (int j = 2 * i - 1; j >= 1; j--) printf("%c", a);
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    init(n);
    return 0;
}

