#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

void funA(int);
void funB(int);
//两个函数互相调用，需要写申明
#if 1
void funB(int n) {
    if (n == 0) return ;
    printf("funB : %d\n", n);
    funA(n - 1);
    return ;
}

void funA(int n) {
    if (n == 0)  return ;
    printf("funA : %d\n", n);
    funB(n - 1);
    return ;
}
#endif


int main() {
    add(2, 3);
    funA(5);
    return 0;
}

