#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

typedef struct priority_queue {
    int *data;
    int cnt, size;//记录当前元素个数、全部元素数量
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));//下标从1开始
    q->cnt = 0;
    q->size = n;
    return q;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int top(priority_queue *q) {//输出队首元素
    return q->data[1];
}

int push(priority_queue *q, int val ) { //插入元素val
    if (q == NULL) return 0;//优先队列不存在
    if (q->cnt == q->size) return 0;//优先队列满了，不能插入
    //q->cnt++;
    q->data[++q->cnt] = val;
    //优先队列调整，自下向上
    int ind = q->cnt;
    while (ind >> 1 && q->data[ind] < q->data[ind >> 1]) {//当当前节点有父节点，且当前节点>父节点的值(大顶堆)
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}
int pop(priority_queue * q) {//头部弹出,堆顶弹出且调整
    if (q == NULL) return 0;//优先队列不存在
    if (empty(q)) return 0;//优先队列为空
    q->data[1] = q->data[q->cnt--];//取优先队列的最后一个元素赋值给头部，头部弹出
    //q->cnt--;
    //维护优先队列，自顶向下
    int ind = 1;
    while ((ind << 1) <= q->cnt) {//当前优先队列还有子节点
        int temp = ind, l = ind << 1, r = ind << 1 | 1;// r = ind * 2 + 1
        if (q->data[l] > q->data[temp]) temp = l;
        if (r <= q->cnt && q->data[r] > q->data[temp]) temp = r;//不一定有右孩子
        if (temp == ind) swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return 1;
}

void clear(priority_queue * q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);

    priority_queue *q = init(n);

    for (int i = 0, a, b; i < n; i++) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d", &b);
            push(q, b);
        } else if (a == 2) {
            if (empty(q)) printf("empty\n");
            else printf("%d\n", top(q));
        }
        else {
            if (!empty(q)) pop(q);
        }
    }
    clear(q);
    return 0;
}


