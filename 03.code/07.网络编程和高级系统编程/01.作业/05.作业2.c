#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    
    int opt;
    while ((opt = getopt(argc, argv, "alm:o::")) != -1) {
        if (opt == 'm')
            printf("%s \n", optarg);
    }
    if (argc == 1) {
        pid_t pid;
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) {
        //    printf("start vim\n");
            execlp("vim", "vim", "06.test.txt", NULL);
            return 1;
    
        }
        wait(NULL);
       // printf("After vim terminated!\n");
       // sleep(2);
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) {
        //    printf("start printf\n");
            execlp("cat", "cat", "06.test.txt", NULL);
            return 2;
        }
        wait(NULL);
        //printf("\nAfter printf terminated!\n");
        //sleep(2);
        if((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) {
         //   printf("delete txt\n");
            execlp("rm", "rm", "06.test.txt", NULL);
            return 3;
        }
        wait(NULL);
       // printf("after delete txt\n");
        
    }

            



    return 0;
}

