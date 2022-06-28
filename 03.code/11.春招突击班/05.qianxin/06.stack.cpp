#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct stack {
    int *data;
    int top;
    int size;
} stack;

stack *init(int _size) {
    stack *s = (stack *)malloc(sizeof(stack));
    s->data = (int *)malloc(sizeof(int) * _size);
    s->size = _size;
    s->top = -1;
    return s;
}

int push(stack *s, int val) {
    if (s == NULL) return -1;
    if (s->top == s->size) return -1;
    s->data[++s->top] = val;
    return 1;
}
int empty(stack *s) {
    return s->top == -1;
}
int pop(stack *s) {
    if (s == NULL) return -1;
    if (empty(s)) return -1;
    s->top--;
    return 1;
}

int top(stack *s) {
    return s->data[s->top];
}


void clear(stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

void output(stack *s) {//打印栈
    if (s == NULL) return ;
    if (empty(s)) {
        printf("stack empty!\n");
        return ;
    }
    printf("[");
    for (int i = 0; i <= s->top; i++) {
        i && printf(",");
        printf("%d", s->data[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    stack *s = init(20);
    for (int i = 0; i < max_op; i++) {
       int value = rand() % 100;
       int op = rand() % 4;
       switch (op) {
       case 0:
       case 1:
       case 2: {
                printf("push %d to the stack= %d\n", value, push(s, value));
               }break;
       case 3: {
                   printf("pop %d from the stack!", top(s));
                   printf("result = %d\n", pop(s));
               }break;

       }
       output(s);
       printf("\n");
    }
    #undef max_op
    clear(s);
    return 0;
}

