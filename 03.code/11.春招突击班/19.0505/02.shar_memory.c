#include <sys/shm.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <pthread.h>//加入互斥锁，保证数据安全  



int main() {
    // 互斥锁    
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);


    const char data[] = "hello shar_memory !";
    key_t key = (key_t)666;
    int data_size = strlen(data) + 1;
    printf("%s data size is : %d \n", data, data_size);

    // 第一步：创建共享内存  
    int shmid = shmget(key, data_size, 0644 | IPC_CREAT); 
    // 创建一个新共享内存段或取得一个既有共享内存段的标识符
    // 生成一个相应的共享内存标识符
    // size以字节为单位指定需要共享的内存容量
    // 返回共享内存标识符
    if (shmid == -1) {
        perror("shmget failed\n");
        exit(EXIT_FAILURE);
    }
    printf("shmid = %d \n", shmid);
    //第二步：进程将共享内存连接到自身的地址空间
    void *shmaddr = shmat(shmid, NULL, 0);
    // 将 shmid 标识的共享内存段附加到调用进程的虚拟地址空间中。
    // 返回附加共享内存段的地址。
    if (shmaddr == (void *)-1) {
        perror("shmat failed\n");
        exit(EXIT_FAILURE);
    }
    //当写入数据前，加锁
    pthread_mutex_lock(&mutex);

    //第三步：向共享内存中写入数据
    memset(shmaddr, 0, data_size);
    memcpy(shmaddr, &data, strlen(data));  

    //写入数据后，解锁
    pthread_mutex_unlock(&mutex);

    //第四步：进程分离共享内存
    if (shmdt(shmaddr) == -1) {
        perror("shmdt failed\n");
        exit(EXIT_FAILURE);
    }
    printf("write done!\n");

    return 0;

}

