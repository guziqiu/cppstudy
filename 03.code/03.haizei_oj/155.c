#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[35] = {0};
    int j = 2;
    a[1] = 3;
    printf("%d\n", a[1]);
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + j; 
        j += 2;
        printf("%d\n", a[i]);
        a[0] += a[i];
    }
    printf("%d\n", a[0] + a[1]);
    return 0;
}

