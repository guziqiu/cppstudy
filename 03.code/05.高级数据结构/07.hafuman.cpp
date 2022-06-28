#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char ch;
    double p;
    struct Node *lchild,*rchild;
} Node;


Node *getNewNode(int key, double per) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = key;
    p->lchild = p->rchild = NULL;
    p->p = per;
    return p;
}
Node *CombinNode(Node *a, Node b)



int main() {


    return 0;
}
