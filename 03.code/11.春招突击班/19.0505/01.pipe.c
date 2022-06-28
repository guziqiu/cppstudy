#include<unistd.h>    
#include<stdio.h>    
#include<stdlib.h>    
#include<string.h>    
#define INPUT  0     
#define OUTPUT 1

int main() {
    
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if (pid < 0) {
        printf("fork error !\n");
        exit(-1);
    } else if (pid == 0) {
        printf("我是子进程！...\n");
        close(fd[INPUT]);
        write(fd[OUTPUT], "hello pipe!", strlen("hello pipe !"));
        exit(0);
    } else {
        printf("我说父进程... \n");
        close(fd[OUTPUT]);
        char buff[225];
        int output = read(fd[INPUT], buff, sizeof(buff));
        printf("%d bytes of data from child process : %s \n", output, buff);
    }
    return 0;
        


    return 0;
}

