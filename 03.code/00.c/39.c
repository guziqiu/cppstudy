#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define offset(T, a) ({\
    T temp;\
    (char *)(&temp.a) - (char *)(&temp);\
})
struct Data {
    int a;
    double b;
    char c;
};

int main(int argc, char *argv[], char *env[]) {
    

  //结构体类型和变量的相对地址偏移量
    printf("%ld\n", offset(struct Data, a));
    printf("%ld\n", offset(struct Data, b));
    printf("%ld\n", offset(struct Data, c));

    
    return 0;
}
