#include "00.head.h"

struct MyArg {
    char name[20];
    int age;
};

void *print(void *arg) {
    struct MyArg copyMyarg;
    copyMyarg = *(struct MyArg *)arg;//防止在执行过程中会被其他线程改变，所以先拷贝下来
    struct MyArg *in;
    in = (struct MyArg *)arg;
    
    printf("In Thread\n");
    printf("%s is %d years old!\n", in->name, in->age);
    printf("%s is %d years old!\n", copyMyarg.name, copyMyarg.age);
}

int main() {
    pthread_t thread;
    char name[20];
    int age = 18;
    struct MyArg arg;
    strcpy(arg.name, "古子秋");
    arg.age = age;
    pthread_create(&thread, NULL, print, &arg);
    usleep(1);
    return 0;
}

