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
        printf("fork error\n");
        exit(-1);
    } else if (pid == 0) {
        printf("Child process is start...\n");
        // 子进程向父进程写数据
        close(fd[INPUT]);
        char buff[255];
        scanf("%s", buff);
        write(fd[OUTPUT], buff, strlen(buff));
        exit(0);
    } else {
        // 执行父进程
        printf("Parent process is starting... \n");
        close(fd[OUTPUT]);
        char buff[255];
        int output = read(fd[INPUT], buff, sizeof(buff));
        printf("%d bytes of data from chile process : %s\n", output, buff);
    }

    return 0;
}

