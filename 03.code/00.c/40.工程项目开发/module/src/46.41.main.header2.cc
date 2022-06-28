
#include <stdio.h>
#include <42.41.main.header1.h>

void funcC(int a, int b) {
    printf("funcC ：%d\n", a + b);
    funcA(a);
    return ;
}
