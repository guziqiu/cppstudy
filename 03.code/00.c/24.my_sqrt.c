#include <stdio.h>
#include <math.h>
double func(double x) {
    return x * x;
}

double binary_search(double (*arr)(double),  double x) {
    double head = 0;
    double tail = x;
    double mid;
    if (tail < 1) tail = 1;
    #define EPLS 1e-15
    while (tail - head > EPLS) {
        mid = (head + tail) / 2.0;
        if(arr(mid) > x ) tail = mid;
        else head = mid;
    }
    #undef EPLS
    return head;

}
double my_sqrt(double x) {
    return binary_search(func, x);
}

int main()
{   double x;
    while(~scanf("%lf", &x)) {
        printf("my_sqrt %g  ==> %g\n", x, binary_search(func, x));
        printf("my_sqrt %g  ==> %g\n", x, my_sqrt(x));
        printf("sqrt %g ==> %g\n", x, sqrt(x));
    }
    return 0;
}

