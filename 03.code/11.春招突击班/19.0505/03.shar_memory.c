#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {

    const char data[] = "hello sharmemory!\n";
    key_t key = (key_t)666;
    int data_size = strlen(data) + 1;
    printf("data size %d\n", data_size);

    //第一步：创建共享内存
    int shmid = shmget(key, data_size, 0644 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed\n");
        exit(EXIT_FAILURE);
    }
    //第二步：进程将共享内存连接到自身的地址空间
    void *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *)-1) {
        perror("shmat failed\n");
        exit(EXIT_FAILURE);
    }
    
    //第三步：从共享内存中读入数据
    printf("read from shared memory: %s\n", (char *)shmaddr);
    //第四步：进程分离共享内存
    if (shmdt(shmaddr) == -1) {
        perror("shmdt failed\n");
        exit(EXIT_FAILURE);
    }
    //第五步：删除共享内存
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl delete shared memory failed\n");
        exit(EXIT_FAILURE);
    }











    
    return 0;
}

