#include "00.head.h"
int main() {

    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork()");//fork出错，大部分是因为内存不够
        exit(1);
    }
    int num;
    scanf("%d", &num);
    printf("%d\n", num);
    if (pid == 0) {//==>一定是父进程先执行吗?
        //基于内核算法，极大概率先执行父进程
        //父进程和子进程相互独立，谁先跑都没有关系，由调度决定
        //父进程正在执行，此时复制父进程，所以一般会先执行父进程
        //如果此时cpu强制停用父进程，先执行别的进程，则可能会出现子进程先执行
        printf("Child Process!\n");
    } else {
        printf("Parent Process\n");//父子进程有同一份代码，孩子从11行开始
    }
    //父进程管理子进程，
    return 0;
}

