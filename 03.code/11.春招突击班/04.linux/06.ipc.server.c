#include "04.head.h"
#include "05.ipcchat.h"

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
  	//初始化一个互斥锁     //互斥锁标识         //互斥锁属性  

    pthread_condattr_t c_attr;
    pthread_condattr_init(&c_attr);
    pthread_condattr_setpshared(&c_attr, PTHREAD_PROCESS_SHARED);
    pthread_cond_init(&shar_memory->cond, &c_attr);
    //初始化条件变量  

    while (1) {
       // 对互斥锁上锁，若互斥锁已经上锁，则调用者一直阻塞，// 直到互斥锁解锁后再上锁。  
        pthread_mutex_lock(&shar_memory->mutex);
        printf("Server got the Mutex!\n");
        //阻塞等待  
        pthread_cond_wait(&shar_memory->cond, &shar_memory->mutex);
        printf("Server got the cond signal!\n");
        printf("<%s> : %s.\n", shar_memory->name, shar_memory->msg);
        memset(shar_memory->msg, 0, sizeof(shar_memory->msg));
        pthread_mutex_unlock(&shar_memory->mutex);// 对指定的互斥锁解锁。  

    }

    return 0;
}
