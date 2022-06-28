#include "00.head.h"
//#define INS 5

char num_file[] = "./.num";
char lock_file[] = "./.lock";
struct Msg {
    int now;
    int sum;
};

struct Msg num;

size_t set_num(struct Msg *msg) {
    FILE *f = fopen(num_file, "w");
    if (f == NULL) {
        fclose(f);
        perror("fopen");
        return -1;
    }
    size_t nwrite = fwrite(msg, 1, sizeof(struct Msg), f);
    fflush(f);
    fclose(f);
    return nwrite;
}

size_t get_num(struct Msg *msg) {
    FILE *f = fopen(num_file, "r");
    if (f == NULL) {
        fclose(f);
        perror("fopen()");
        return -1;
    }
    
    size_t nread = fread(msg, 1, sizeof(struct Msg), f);
    fflush(f);
    fclose(f);
    return nread;
}

void do_add(int end, int pid_num) {
    while (1) {
        FILE *lock = fopen(lock_file, "w");
        if (lock == NULL) {
            perror("fopen()");
            exit(1);
        }
        //flock(lock->_fileno, LOCK_EX);
        if (get_num(&num) < 0) {
            fclose(lock);
            continue;
        }
        
        if (num.now > end) {
            fclose(lock);
            break;
        }
        num.sum += num.now;
        num.now++;
        printf("the %dth child : now = %d, sum = %d\n", pid_num, num.now, num.sum);
        set_num(&num);
        //flock(lock->_fileno, LOCK_UN);
        fclose(lock);
    }

}

int main(int argc, char *argv[]) {
    
    int opt, start = 0, end = 0, ins = 0;
    while ((opt = getopt(argc, argv, "s:e:i:")) != -1) {
        switch (opt) {
        case 's':
            start = atoi(optarg);
            break;
        case 'e':
            end = atoi(optarg);
            break;
        case 'i':
            ins = atoi(optarg);
            break;
        default:
            fprintf(stderr, "Usage : %s -s start_num -e end_num -i\n", argv[0]);
            exit(1);
        }
    }
    printf("start = %d\n end = %d\n", start, end);
    
    num.now = 0;
    num.sum = 0;
    set_num(&num);
    
    pid_t pid;    
    int x = 0;
    for (int i = 1; i <= ins; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(-1);
        }
        if (pid == 0) {//孩子
            x = i;
            break;
        }
    }
    if (pid != 0) {
        for (int i = 0; i < ins; i++) {
            wait(NULL);
        }
        
        //printf("I am father!\n");
        //sleep(100);
    } else {
        do_add(end, x);
    }
    get_num(&num);
    printf("sum = %d\n", num.sum);

    return 0;
}

