#include <stdio.h>

int func(int x) {
    if (x <= 0) return 0;
    else if (x == 1) return 1;
    else if (x > 1 && x % 2 == 0) return 3 * func(x / 2) - 1;
    else return 3 * func((x + 1) / 2) - 1;
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d\n", func(x));
    return 0;
}

