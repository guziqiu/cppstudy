#include "00.head.h"
int main() {

    pid_t pid;
    int status;
    int i;
    for (i = 1; i <= 10; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if (pid == 0) break;;
    }
    if (pid == 0) {
        printf(" I am %d Child Process!\n", i);
        
        sleep(500);
    //    return 1;
    } //else {
        //    printf("Parent Process\n");
        //    wait(&status);
        //    printf("--wait status = %d \n", status);
   // }
   
   return 0;
}

