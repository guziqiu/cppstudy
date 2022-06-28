#include <iostream>
#include <cstdio>
 
int func(int x, int a, int b, int n) {
    if (x - a < 0) x = 0;
    if (n == 0) return 0;
    return std::max(x + func(x - a, a, b, n - 1), func(x + b, a, b, n - 1));
}



int main() {
    int t;
    scanf("%d", &t);
    int x, a, b, n;

    for (int i = 0; i < t; i++) {
        scanf("%d %d %d %d", &x, &a, &b, &n);
        printf("%d\n", func(x, a, b, n));
    }





    return 0;
}

