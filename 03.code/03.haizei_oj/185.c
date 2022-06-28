#include <stdio.h>

int fn(int n) {
    if(n == 1) return 1;
    else if(n == 2) return 2;
    else return fn(n - 2) + fn(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fn(n));

    return 0;
}

