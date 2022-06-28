#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
 
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}


typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->cnt = 0;
    q->size = n;
    return q;
}

int top(priority_queue *q) {
    return q->data[1];
}
int empty(priority_queue *q) {
    return q->cnt == 0;
}

int push(priority_queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->size) return 0;
    q->data[++q->cnt] = val;
    int ind = q->cnt;
    while ((ind >> 1) && (q->data[ind >> 1] < q->data[ind])) {
        swap(q->data[ind >> 1], q->data[ind]);
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *q) {
    if (q == NULL) return 0;
    if(empty(q)) return 0;
    q->data[1] = q->data[q->cnt--];
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->data[temp] < q->data[l]) temp = l;
        if (r <= q->cnt && q->data[temp] < q->data[r]) temp = r;
        if (temp == ind) break;
        swap(q->data[temp], q->data[ind]);
        ind = temp;
    }
    return 1;
}



void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

void output(priority_queue *q) {
    for (int i = 0; i < q->size; i++) {
        cout << q->data[i] << " ";
    }
    cout << endl;
}


int main() {
    srand(time(0));
    #define MAX_OP 20
    priority_queue *q = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        push(q, val);
        printf("insert %d to the priority_queue !\n", val);
    }
    output(q);
    for (int i = 0; i < MAX_OP; i++) {
        printf("%d ", top(q));
        pop(q);
    }
    printf("\n");
    #undef MAX_OP
    clear(q);
    return 0;
}
