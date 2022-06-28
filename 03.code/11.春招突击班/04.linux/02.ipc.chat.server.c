#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/file.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
//socket
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
 
struct Msg{
    char name[20];
    char msg[1024];
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};


struct Msg *shar_memory = NULL;
//服务端
int main() {
    int shmid;
    key_t key = ftok(".", 202101);
    if ((shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shar_memory = (struct Msg *)shmat(shmid, NULL, 0)) == (struct Msg *)-1) {
        perror("shmat");
        exit(-1);
    }
    //初始化
    memset(shar_memory, 0, sizeof(struct Msg));
    pthread_mutexattr_t m_attr;
    pthread_mutexattr_init(&m_attr);
    pthread_mutexattr_setpshared(&m_attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&shar_memory->mutex, &m_attr);
    
    pthread_condattr_t c_attr;
    pthread_condattr_init(&c_attr);
    pthread_condattr_setpshared(&c_attr, PTHREAD_PROCESS_SHARED);
    pthread_cond_init(&shar_memory->cond, &c_attr);

    while (1) {
        pthread_mutex_lock(&shar_memory->mutex);
        printf("Server got the Mutex!\n");
        pthread_cond_wait(&shar_memory->cond, &shar_memory->mutex);
        printf("Server got the cond signal!\n");
        printf("<%s> : %s.\n", shar_memory->name, shar_memory->msg);
        memset(shar_memory->msg, 0, sizeof(shar_memory->msg));
        pthread_mutex_unlock(&shar_memory->mutex);

    }






    return 0;
}

