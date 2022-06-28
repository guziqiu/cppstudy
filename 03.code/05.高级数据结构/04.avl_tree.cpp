#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data, height;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;//假的空节点
__attribute__((constructor))
#define NIL (&__NIL)
void init_NIL() {
    NIL->data = 0;
    NIL->height = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int _data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = _data;
    node->lchild = node->rchild = NIL;
    node->height = 1;
    return node;
}

void update_height(Node *root) {
    root->height = (root->lchild->height > root->rchild->height ? root->lchild->height : root->rchild->height) + 1;
    return ;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *right_rotate(Node *root) {//对称
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *maintain(Node *root) {
    if (abs(root->lchild->height - root->rchild->height) <= 1) return root;
    if (root->lchild->height > root->rchild->height) {//L大左旋
        if (root->lchild->lchild->height < root->lchild->rchild->height)//LR小右旋 
            root->lchild = left_rotate(root->lchild);
        root = right_rotate(root);
    } else {
        if (root->rchild->rchild->height < root->lchild->rchild->height)//RL小左旋 
            root->rchild = right_rotate(root->lchild);//小右旋
        root = left_rotate(root);//大左旋
    }
    return root;
}

Node *insert(Node *root, int val) {
    if (root == NIL) return getNewNode(val);
    if (root->data == val) return root;//不需要插入操作
    if (val < root->data) {
        root->lchild = insert(root->lchild, val);
    } else {
        root->rchild = insert(root->rchild, val);
    }
    update_height(root);

    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp && temp->lchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int val) {
    if (root == NIL) return NIL;
    if (val < root->data) {
        root->lchild = erase(root->lchild, val);
    } else if (val > root->data) {
        root->rchild = erase(root->rchild, val);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->data = temp->data;
            root->lchild = erase(root->lchild, temp->data);
        }
    }
    update_height(root);
    return maintain(root);
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d[%d],%d,%d)\n", 
           root->data, root->height, 
           root->lchild->data, 
           root->rchild->data);
    output(root->lchild);
    output(root->rchild);
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
        case 0: root = erase(root, val);
        case 1:
        case 2:
        case 3: root = insert(root, val);
        }
        output(root);
        printf("--------------\n");
    }
    clear(root);

    return 0;
}

