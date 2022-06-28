#include "00.head.h"
#include "17.ipc.chat.h"

struct Msg *shar_memory = NULL;

int main(int argc, char **argv) {
        
    int opt, shmid;//.,共享内存id
    char name[20] = {0};
    while ((opt = getopt(argc, argv, "n:")) != -1) {
        switch (opt) {
        case 'n':
            strcpy(name, optarg);
            break;
        default:
            fprintf(stderr, "Usage : %s -n name\n", argv[0]);
            exit(1);
        }
    }

    key_t key = ftok(".", 202101);
    if ((shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shar_memory = (struct Msg *)shmat(shmid, NULL, 0)) == (struct Msg *)-1) {
        perror("shmat");
        exit(1);
    }

    while (1) {
        char msg[1024] = {0};
        scanf("%[^\n]s", msg);
        getchar();//吃掉缓冲区的回车键
        if (!strlen(msg)) continue;//字符串为空
        while (1) {
            if (!strlen(shar_memory->msg)) {
                pthread_mutex_lock(&shar_memory->mutex);
            }
        }
        //pthread_mutex_lock(&shar_memory->mutex);
        printf("Sending : %s...\n", msg);
        strcpy(shar_memory->msg, msg);
        strcpy(shar_memory->name, name);
        pthread_cond_signal(&shar_memory->cond);
        pthread_mutex_unlock(&shar_memory->mutex);
        printf("Client signaled the cond\n");
    }



    return 0;
}

