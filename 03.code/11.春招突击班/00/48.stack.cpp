#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct stack {
    int *data;
    int top, size;
} stack;

stack *init(int n) {
    stack *s = (stack *)malloc(sizeof(stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1; // 栈顶指针
    return s;
}

int empty(stack *s) {
    return s->top == -1;
}

int top(stack *s) {
    return s->data[s->top];
}

int push(stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top == s->size - 1) return 0;
    s->data[++s->top] = val;
    return 1;
}

int pop(stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top--;
    return 1;
}

void clear(stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

void output(stack *s) {
    cout << "stack : [";
    for (int i = 0; i <= s->top; i++) {
        i && cout << " ,";
        cout << s->data[i];
    }
    cout << "]";
}

int main() {
    #define MAX_OP 20
    stack *s = init(MAX_OP);
    srand(time(0));

    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4;  
        int val = rand() % 100;
        switch (op) {
        case 0:
        case 1:
        case 2:
            printf("push %d to stack = %d\n", val, push(s, val));
            break;
        case 3:
            if (!empty(s)) printf("seccess to pop! pop %d from stack!\n", top(s)),pop(s);
            break;
        }
        output(s), printf("\n");
    }
    #undef MAX_OP
    clear(s);
    return 0;
}

