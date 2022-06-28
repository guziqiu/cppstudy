#include "00.head.h"

int make_nonblock(int fd);
int main() {
    int age;
    make_nonblock(0);

    sleep(4);
    int ret = scanf("%d", &age);
    printf("guziqiu is %d years old!, ret = %d \n", age, ret);
    perror("scanf");
    
    return 0;
}

