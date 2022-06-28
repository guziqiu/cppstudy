#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct queue {
    int *data;
    int head;
    int tail;
    int length;
} queue;

queue *init(int _length) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->data = (int *)malloc(sizeof(int) * _length);
    q->length = _length;
    q->head = 0;
    q->tail = 0;
    return q;
}

int front(queue *q) {
    return q->data[q->head];
}


int empty(queue *q) {
    return q->tail == q->head;
}

int push(queue *q, int val) {
    if (q == NULL) return -1;
    if (q->tail == q->length) return -1;
    q->data[q->tail++] = val;
    return 1;
}
int pop(queue *q) {
    if (q == NULL) return -1;
    if (empty(q)) return -1;
    q->head++;
    return 1;
}


void clear(queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

void output(queue *q) {
    if (q == NULL) return ;
    printf("Queue : [");
    for (int i = q->head, j = 0; i < q->tail; i++,j++) {
        j && printf(",");
        printf("%d", q->data[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    queue *q = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int value = rand() % 100;
        int op = rand() % 4;
        switch (op) {
        case 0:
        case 1:
        case 2:{
            printf("push %d to the Queue !", value);
            printf("result = %d\n", push(q, value));

        }break;
        case 3: {
             printf("pop %d from th Queue !", front(q));
             printf("result = %d\n", pop(q));
        }break;
        }
        output(q);
        printf("\n");
    }

    #undef max_op
    clear(q);
    return 0;
}

