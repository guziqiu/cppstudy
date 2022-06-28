#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) { \
    __typeof(a) __c = a; \
    a = b, b = __c; \
}

typedef struct Node {
    char ch;
    double p;//概率值
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(char _ch, double _per) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = _ch;
    p->p = _per;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *CombinNode(Node *a, Node *b) {//合并成新结点
    Node *p = getNewNode(0, a->p + b->p);
    p->lchild = a;
    p->rchild = b;
    return p;
}

void pick_min(Node **arr, int n) {//找到概率最小的结点
    for (int j = n - 1; j >= 0; --j) {
        if (arr[n]->p > arr[j]->p) {
            swap(arr[n], arr[j]);
        }
    }
    return ;
}

Node *getHaffmanTree(Node **arr, int n) {//生成n个结点的哈夫曼树，n个结点循环n-1次形成树
    for (int i = 1; i < n; i++) {
        pick_min(arr, n - i);//最小的放在最后面，次之放倒数第二
        pick_min(arr, n - i - 1);
        arr[n - i - 1] = CombinNode(arr[n - i], arr[n - i - 1]);
    }
    return arr[0];
}

void __output_encode(Node *root, char *str, int k) {
    str[k] = 0;
    if (root->lchild == NULL && root->rchild == NULL) {//根节点
        printf("%c %s\n", root->ch, str);
        return ;
    }
    str[k] = '0';
    __output_encode(root->lchild, str, k + 1);//左0右1
    str[k] = '1';
    __output_encode(root->rchild, str, k + 1);
    return ;
}

void output_encode(Node *root) {//
    char str[100];
    __output_encode(root, str, 0);
    return ;
}


void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int main() {
    int n;
    Node **arr;//数组
    scanf("%d", &n);//要输节点数量
    arr = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++) {
        char ch[10];
        double p;
        scanf("%s%lf", ch, &p);//输入节点
        arr[i] = getNewNode(ch[0], p);
    }
    Node *root = getHaffmanTree(arr, n);//获取哈夫曼树
    output_encode(root);//输出哈夫曼树
    clear(root);
    free(arr);
    return 0;
    
    return 0;
}

