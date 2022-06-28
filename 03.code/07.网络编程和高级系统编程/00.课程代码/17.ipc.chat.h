
struct Msg{
    char name[20];
    char msg[1024];
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};
