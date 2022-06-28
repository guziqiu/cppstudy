#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {//定义节点
    int data;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {//定义树
    Node *root;
    int n;//节点个数
} Tree;

Node *getNewNode (int value) {//节点初始化
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->lchild = node->rchild = NULL;
    return node;
}

Tree *getNewTree() {//初始化树
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Node *insert_node(Node *root, int value, int *flag) {//
    if (root == NULL) {
        *flag = 1;
        return getNewNode(value);
    }
    if (root->data == value) return root;
    if (root->data > value) root->lchild = insert_node(root->lchild, value, flag);//递归插入，直到节点为空
    else root->rchild = insert_node(root->rchild, value, flag);
    return root;
}

void insert(Tree *tree, int value) {//二叉查找树/二叉排序树
    int flag = 0;
    tree->root = insert_node(tree->root, value, &flag);
    tree->n += flag;
    return ;    
}

void clearNode(Node *node) {//释放节点
    if (node == NULL) return ;
    clearNode(node->lchild);
    clearNode(node->rchild);
    free(node);
    return ;
}

void clear(Tree *tree) {//释放树申请的内存
    if (tree == NULL) return ;
    clearNode(tree->root);
    free(tree);
    return ;
}

//树的遍历
//1.先序遍历
void pre_order_node(Node *node) {//先序遍历（递归）
    if (node == NULL) return ;
    printf("%d ", node->data);
    pre_order_node(node->lchild);
    pre_order_node(node->rchild);
    return ;
}
void pre_order(Tree *tree) {//先序遍历
    if (tree == NULL) return ;
    printf("pre_order : ");
    pre_order_node(tree->root);
    printf("\n");
    return ;
}

//2.中序遍历
void in_order_node(Node *node) {
    if (node == NULL) return ;
    in_order_node(node->lchild);
    printf("%d ", node->data);
    in_order_node(node->rchild);
    return ;
}
void in_order(Tree *tree) {//中序遍历
    if (tree == NULL) return ;
    printf("pre_order : ");
    in_order_node(tree->root);
    printf("\n");
    return ;
}


//3.后序遍历
void post_order_node(Node *node) {
    if (node == NULL) return ;
    post_order_node(node->lchild);
    post_order_node(node->rchild);
    printf("%d ", node->data);
    return ;
}
void post_order(Tree *tree) {//后序遍历
    if (tree == NULL) return ;
    printf("pre_order : ");
    post_order_node(tree->root);
    printf("\n");
    return ;
}

void output_node(Node *root) {
    if (root == NULL) return ;
    printf("%d", root->data);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    output_node(root->lchild);
    printf(",");
    output_node(root->rchild);
    printf(")");
    return ;
}

void output(Tree *tree) {
    if (tree == NULL) return ;
    printf("tree(%d) : ", tree->n);
    output_node(tree->root);
    printf("\n");
    return ;
}


int main() {
    srand(time(0));
    Tree *tree = getNewTree();
    #define max_op 4
    for (int i = 0; i < max_op; i++) {
        int value = rand() % 100;
        insert(tree, value);
        output(tree);
    }
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    #undef max_op
    clear(tree);

    return 0;
}

