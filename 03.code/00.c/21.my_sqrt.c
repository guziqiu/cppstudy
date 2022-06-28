#include <stdio.h>
#include <math.h>

double func(double x) {
    return x * x;
}

double binary_search(double (*arr)(double), double n) {
    double head = 0;
    double tail = n;
    double mid;

    if (n < 1.0) tail = 1.0;
    #define EPLS 1e-8
    while (tail - head > EPLS) {
        mid = (head + tail) / 2.0;
        if(arr(mid) < n) head = mid;
        else tail = mid;
    }
    #undef EPLS
    return head;

}

int main()
{
    double n;
    scanf("%lf", &n);
    printf("my_sqrt(%lf) = %g\n", n, binary_search(func, n));
    printf("sqrt(%lf) = %g\n", n, sqrt(n)) ;
    return 0;
}

