#include <stdio.h>
#include <math.h>

double F(double x, double n) {
    return x * x - n;
}

double f(double x) {
    return 2 * x;
}

double NewTon_mysqrt(double (*F)(double, double), double (*f)(double), double n) {
    double x = n;
    #define EPLS 1e-10
    while (fabs(F(x, n)) > EPLS) {
        x -= F(x, n) / f(x);
    }
    #undef EPLS
    return x;
}
double mysqrt(double n) {
    return NewTon_mysqrt(F, f, n);
}
int main()
{
    double n;
    while (~scanf("%lf", &n)) {
        printf("NewTon_mysqrt %g ==> %g\n", n, NewTon_mysqrt(F, f, n));
        printf("       my_sqrt %g ==> %g\n", n, mysqrt(n));
        printf("         sqrt %g ==> %g\n", n, sqrt(n));
    }
    return 0;
}

