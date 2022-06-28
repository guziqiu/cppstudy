#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a,b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a,32)

//结构定义+结构操作
typedef struct Queue {
    int *data;
    int head;//头结点
    int tail;//尾结点，最后一个元素的下一个为空的位置
    int length;
    int count;//记录队列中元素的个数
} Queue;

//结构操作
Queue *init(int n) {//初始化队列
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = (int *)malloc(sizeof(int) * n);
    queue->head = queue->tail = 0;
    queue->length = n;
    queue->count = 0;
    return queue;
}

int front(Queue *queue) {
    return queue->data[queue->head];
}

int empty(Queue *queue){
   // return queue->head == queue->tail; 
   return queue->count == 0;
}

int expand(Queue *queue) {
    int extr_size = queue->length;
    int *temp_queue;
    while (extr_size) {
        temp_queue = (int *)malloc(sizeof(int) * (extr_size + queue->length));
        if (temp_queue) break;
        extr_size >>= 1;
    }
    if (temp_queue == NULL) return 0;
    for (int i = queue->head, j = 0; j < queue->count; j++) {
        temp_queue[j] = queue->data[(i + j) % queue->length];
    }
    free(queue->data);
    queue->data = temp_queue;
    queue->length += extr_size;
    queue->head = 0;
    queue->tail = queue->count;
    return 1;
}

int push(Queue *queue, int value) {
    if(queue == NULL) return 0;
    if(queue->count == queue->length) {//扩容
        if(!expand(queue)) return 0;
        printf(GREEN("ecpand sucessfull!Queue->size = %d\n"), queue->length);
    }
    queue->data[queue->tail++] = value;
    //queue->tail++;
    if (queue->tail == queue->length) queue->tail = 0;//queue->tail %= queue->length;
    queue->count += 1;
    return 1;
}

int pop(Queue *queue) {
    if (queue == NULL) return 0;
    if (empty(queue)) return 0;
    queue->head++;
    if (queue->head == queue->length) queue->head = 0;
    queue->count--;
    return 1;
}

void output(Queue *queue) {
    if (queue == NULL) return ;
    printf("Queue : [");
    for (int i = queue->head, j = 0; j < queue->count; i++,j++) {
        j && printf(",");
        printf("%d", queue->data[i % queue->length]);
    }
    printf("]\n");
    return ;
}

void clear(Queue *queue) {//清空队列
    if(queue == NULL) return ;
    free(queue->data);
    queue->data = NULL;
    free(queue);
    queue = NULL;
    return ;
}


int main() {
    srand(time(0));
    #define max_op 20
    Queue *queue = init(2);
    for (int i = 0; i < max_op; i++) {
        int value = rand() % 100;
        int op = rand() % 4;
        switch (op) {
        case 0:
        case 1:
        case 2:{
            printf("push %d to the Queue !", value);
            printf("result = %d\n", push(queue, value));

        }break;
        case 3: {
             printf("pop %d from th Queue !", value); 
             printf("result = %d\n", pop(queue));
        }break;
        }
        output(queue);
        printf("\n");
    }

    #undef max_op
    clear(queue);
    return 0;
}

