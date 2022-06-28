

struct task_queue{
    //循环队列
    int size;
    int total;
    int head;
    int tail;
    char **data;
    pthread_mutex_t mutex;//加锁
    pthread_cond_t cond;//检测是否又客人
};

void task_queue_init(struct task_queue *taskQueue, int size);//建立等待区，等待区又size大小
void task_queue_push(struct task_queue *taskQueue, char *str);//str入队列
char *task_queue_pop(struct task_queue *taskQueue);//str入队列



