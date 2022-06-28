#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;


#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct Queue {
   int *data; //  首地址
   int head, tail, size,  count;
} queue;

queue *init(int n) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->size = n;
    q->head = q->tail = 0;
    q->count = 0;
    return q;
}

int empty(queue *q) {
    if (q == NULL) return -1;
    return q->count == 0;
}

int front(queue *q) {
    return q->data[q->head];
}

int expand(queue *q) {
    int extr_size = q->size;
    int *p;
    while (extr_size) {
        p = (int *)malloc(sizeof(int) * (q->size + extr_size));
        if (p != NULL) break;
        extr_size >>= 1;
    }
    if (p == NULL) return 0;
    for (int i = q->head, j = 0; j < q->count; j++) {
        p[j] = q->data[(i + j) % q->size];
    }
    free(q->data);
    q->data = p;
    q->head = 0;
    q->size += extr_size;
    q->tail = q->count;
    return 1;
}

int push(queue *q, int val) {
    if (q == NULL) return 0;
    if (q->count == q->size) {
        if (!expand(q)) return 0;
        printf(GREEN("success to expand ! the size = %d \n"), q->size);
    }
    q->data[q->tail++] = val;
    if (q->tail == q->size) q->tail = 0;
    q->count++;
    return 1;
}

int pop(queue *q) {
    if (q == NULL) return -1;
    if (empty(q)) return 0;
    q->head += 1;
    if (q->head == q->size) q->head = 0;
    q->count--;
    return 1;
}

void output(queue *q) {
    cout << "queue : [";
    for (int i = q->head, j = 0; j < q->count; j++) {
        j && cout << " ";
        cout << q->data[(i + j) % q->size];
    }
    cout << "]" << endl;
    return ;
}

void clear(queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    #define MAX_OP 20
    queue *q = init(3);
    srand(time(0));
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4;
        int val = rand() % 100;
        switch (op) {
        case 0:
        case 1:
        case 2:
            printf("push %d to queue = %d\n", val, push(q, val));
            break;
        case 3:
            if (!empty(q)) printf("success to pop!\n pop %d from the queue \n", front(q)), pop(q);
            else printf("fail to pop ! the queue is empty!\n");
            break;
        }
        output(q), cout << endl;;
    }
    #undef MAX_OP
    clear(q);
    
    return 0;
}

