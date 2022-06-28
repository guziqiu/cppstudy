#include <stdio.h>
#include <stdlib.h>

#define KEY(n) (n ? n->data : 0)
#define SIZE(n) (n ? n->size : 0)
#define L(n) (n ? n->lchild : NULL)

typedef struct Node {
    int data, size;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int _data) {//初始化
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = _data;
    p->size = 1;
    p->lchild = p->rchild = NULL;
    return p;
}

int search(Node *root, int value) {
    if (root == NULL) return 0;
    if (root->data == value) return 1;
    if (value < root->data) return search(root->lchild, value);
    return search(root->rchild, value);
}

int search_k(Node *root, int k) {
    if (root == NULL) return -1;
    if (SIZE(root->lchild) == k - 1) return root->data;
    if (k <= SIZE(root->lchild)) {
        return search_k(root->lchild, k);
    }
    return search_k(root->rchild, k - SIZE(root->lchild) - 1);
}

void update_size(Node *root) {
    root->size = SIZE(root->lchild)  + SIZE(root->rchild) + 1;
    return ;
}

Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->data == val) return root;
    if (val < root->data) root->lchild = insert(root->lchild, val);
    else root->rchild = insert(root->rchild, val);
    update_size(root);
    return root;
}

Node *predecessor(Node *root) {//前驱
    Node *temp = root->lchild;
    while(temp->rchild) temp = temp->rchild;
    return temp;
}

Node *successor(Node *root) {
    Node *temp = root->rchild;
    while(temp && temp->lchild) temp = temp->lchild;
    return temp;
}

Node *erase(Node *root, int value) {
    if (root == NULL) return NULL;
    if (value < root->data) {
        root->lchild =  erase(root->lchild, value);
    } else if (value > root->data) {
        root->rchild =  erase(root->rchild, value);
    } else {//找到结点
       /* if (root->lchild == NULL && root->rchild == NULL) {
            free(root);
            return NULL;
        } else */
        if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;//返回删除节点的孩子节点，将孩子结点挂载到被删除节点的父亲节点上
        } else {//将两个结点的情况转换为一个结点
            Node *temp = predecessor(root);
            root->data = temp->data;
            root->lchild = erase(root->lchild, temp->data);
        }
    }
    update_size(root);
    return root;
}



void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    printf("%d[%d] ", root->data, SIZE(root));
    output(root->rchild);
    return ;
}
void print(Node *root) {
    printf("(%d[%d], %d, %d)\n", 
           KEY(root), SIZE(root), 
           KEY(root->lchild), KEY(root->rchild)
    );
    return ;
}
void output1(Node *root) {
    if (root == NULL) return ;
    output1(root->lchild);
    print(root);
    output1(root->rchild);
    return ;
}

void output_k(Node *root, int k) {
    if (k == 0 || root == NULL) return ;
    if (k <= SIZE(root->lchild)) output_k(root->lchild, k);
    else {
        output1(root->lchild);
        print(root);
        output_k(root->rchild, k - SIZE(root->lchild) - 1);
    }
    return ;
}

int main() {
    
    int op, val;
    Node *root = NULL;
    while (~scanf("%d%d", &op, &val)) {
        //0：查找 1：插入 2： 删除
        switch (op) {
        case 0:printf("search %d, result : %d \n", val, search(root, val)); break;
        case 1:{
                   printf("insert: %d \n", val);
                   root = insert(root, val); 
                   printf("\n");
               }break;
        case 2:{
                   printf("erase: %d \n", val);
                   root = erase(root, val);
                   printf("\n");
               } break;
        case 3: {
                printf("search k = %d, result : %d\n",
                    val, search_k(root, val));
            } break;
        case 4: {
                printf("output top-%d elements\n", val);
                output_k(root, val);
                printf("------------\n");
            } break;
        }
        
        if (op) {
            printf("\ntree ==> [");
            output(root);
            printf("]\n");
        }
        if (op) output1(root);
        printf("\n------------------\n");
    }
    clear(root);
    

    return 0;
}

