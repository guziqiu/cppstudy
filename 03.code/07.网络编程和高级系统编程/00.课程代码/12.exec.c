#include "00.head.h"

int main() {
    pid_t pid;
    if ((pid = fork()) <  0) {
        perror("fork");
        exit(-1);
    }

    if (pid == 0) {
        printf("start\n");
        execl("./a.out", "haha", "12.exec.c", NULL);
        sleep(10000000);
        printf("END!\n");
    } else {
        wait(NULL);
        printf("After child terminated!\n");
        sleep(4);
    }

    return 0;
}

