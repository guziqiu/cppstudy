#include <stdio.h>

long long n = 1;

long long my_pow(int num) {
    for (int i = 1; i <= num; i++) {
        n = 2 * n;
    }
    if (num == 0) return 1;
    return n;
}

int main()
{
    int num;
    scanf("%d", &num);
    printf("%lld", my_pow(num));

    return 0;
}

