#include "00.head.h"
#include "17.ipc.chat.h"

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

