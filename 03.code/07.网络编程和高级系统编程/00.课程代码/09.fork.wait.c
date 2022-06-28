#include "00.head.h"
int main() {

    pid_t pid;
    int status;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid == 0) {
        sleep(5);
        printf("Child Process!\n");
        return 1;
    } else {
            printf("Parent Process\n");
            wait(&status);
            printf("--wait status = %d \n", status);
    }
   
   return 0;
}

