#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    b = a * 10 + b;
    printf("%d\n", b / (2 * 10 + 6));
    return 0;
}

