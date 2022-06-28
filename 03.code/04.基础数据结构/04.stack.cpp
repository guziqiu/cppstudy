#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct Stack{
    int *data;
    int top;
    int size;
} Stack;

Stack *init(int input_size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (int *)malloc(sizeof(int) * input_size);
    stack->size = input_size;
    stack->top = -1;
    return stack;
} 

int top(Stack *stack) {
    //if (empty(stack)) return 0;
    return stack->data[stack->top];
}

int empty(Stack *stack) {
    return stack->top == -1;
}

int expand(Stack *stack) {
    int *temp_stack;
    int extr_size = stack->size;
    while (extr_size) {
        temp_stack = (int *)realloc(stack->data, sizeof(int) * (extr_size + stack->size));
        if (temp_stack) break;
        extr_size >= 1;
    }
    if (temp_stack == NULL) return 0; //扩容失败
    stack->size += extr_size;
    stack->data = temp_stack; 
    return 1;
}

int push(Stack *stack, int value) {
    if (stack == NULL) return 0;
    if (stack->top == stack->size){ //扩容
        if (!expand(stack)) return 0;
        printf(GREEN("expand successful! stack->size = %d \n"), stack->size);
    }
    stack->data[++stack->top] = value;
    return 1;
}

int pop(Stack *stack) {
    if (stack == NULL) return 0;
    if (empty(stack)) return 0;
    stack->top--;
    return 1;
}

void output(Stack *stack) {
    if (stack == NULL) return ;
    if (empty(stack)) {
        printf("stack empty!\n");
        return ;
    }
    printf("[");
    for (int i = 0; i <= stack->top; i++) {
        i && printf(",");
        printf("%d", stack->data[i]);
    }
    printf("]\n");
    return ;
}

void clear(Stack *stack) {
    if (stack == NULL) return ;
    free(stack->data);
    free(stack);
    return ;
}

int main()
{
    srand(time(0));
    #define max_op 20
    Stack *stack = init(2);
    for (int i = 0; i < max_op; i++) {
       int value = rand() % 100;
       int op = rand() % 4;
       switch (op) {
       case 0:
       case 1:
       case 2: {
                printf("push %d to the stack= %d\n", value, push(stack, value));
               }break;
       case 3: {
                   printf("pop %d from the stack!", top(stack));
                   printf("result = %d\n", pop(stack));
               }break;
            
       }
       output(stack);
       printf("\n");
    }
    #undef max_op
    clear(stack);

    return 0;
}

