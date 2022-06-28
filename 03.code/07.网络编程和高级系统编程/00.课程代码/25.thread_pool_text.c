#include "00.head.h"
#include "24.thread_pool.h"

#define THREAD 5
#define QUEUE 50

void *do_work(void *arg) {
    pthread_detach(pthread_self());//线程分离
    struct task_queue *taskQueue = (struct task_queue *)arg;
    while (1) {
        char *str = task_queue_pop(taskQueue);
        printf("<%d> : %s !\n", pthread_self, str);//线程拿到自己的id
    }

}

int main() {
    pthread_t tid[THREAD];
    struct task_queue taskQueue;
    task_queue_init(&taskQueue, QUEUE);
    char buff[QUEUE][1024] = {0};

    for (int i = 0; i < THREAD; i++) {
        pthread_create(&tid[i], NULL, do_work, (void *) &taskQueue);
    }
    int sub = 0;
    while (1) {
        FILE *fp = fopen("./25.thread_pool_text.c", "r");
        if (fp == NULL) {
            perror("fopen");
            exit(0);
        }
        while (fgets(buff[sub++], 1024, fp) != NULL) {
            task_queue_push(&taskQueue, buff[sub]);
            if (sub == QUEUE) {
                //满了
                sub = 0;
            }
            if (taskQueue.total == taskQueue.size) {
                //
                while (1) {
                    if (taskQueue.total< taskQueue.size) {
                        break;
                    }
                    usleep(10000);
                }
            }
        }
        fclose(fp);
    }
    
    return 0;
}

