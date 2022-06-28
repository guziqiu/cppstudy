#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;
} Tree;

typedef struct Stack {
    Node **data;
    int top;
    int size;
} Stack;

Node *getNewNode(char value) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Stack *init_stack(int n) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (Node **)malloc(sizeof(Node *) * n);
    stack->top = -1;
    stack->size = n;
    return stack;
}

Node *top(Stack *stack) {
    return stack->data[stack->top];
}

int empty(Stack *stack) {
    return stack->top == -1;
}

int push(Stack *stack, Node *value) {
    if (stack == NULL) return 0;
    if (stack->top == stack->size - 1) return 0;
    stack->data[++(stack->top)] = value;
    return 1;
}

int pop(Stack *stack) {
    if (stack == NULL) return 0;
    if (empty(stack)) return 0;
    stack->top--;
    return 1;
}

void clear_stack(Stack *stack) {
    if (stack == NULL) return ;
    free(stack->data);
    free(stack);
    return ;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    clear_node(node->lchild);
    clear_node(node->rchild);
    free(node);
    return ;
}

void clear_tree(Tree *tree) {
    if (tree == NULL) return ;
    clear_node(tree->root);
    free(tree);
    return ;
}
Node *build(char *str, int *node_num) {
    Stack *stack = init_stack(strlen(str));
    int flag = 0;//标记逗号，确定是左孩子还是右孩子,flag = 0,在逗号左侧，左孩子， 1 在逗号右侧右孩子
    Node *temp = NULL;//临时保存新节点
    Node *p = NULL;
    while (str[0]) {
        switch (str[0]) {
        case '(':{
            push(stack, temp);
            flag = 0;
        }break;
        case ')':{
            p = top(stack);
            pop(stack);
        }break;
        case ',': {
            flag = 1;
        } break;
        case ' ': break;
        default:
            temp = getNewNode(str[0]);
            if (!empty(stack) && flag == 0) {
                top(stack)->lchild = temp;
            }else if (!empty(stack) && flag == 1) {
                top(stack)->rchild = temp;
            }
            ++(*node_num);
            break;
        }
        ++str;
    }
    clear_stack(stack);
    if (temp && !p) p = temp;//判空
    return p;
}

void pre_order_node(Node *root) {
    if (root == NULL) return ;
    printf("%c ", root->data);
    pre_order_node(root->lchild);
    pre_order_node(root->rchild);
    return ;
}

void pre_order(Tree *tree) {
    if (tree == NULL) return ;
    printf("pre_order : ");
    pre_order_node(tree->root);
    printf("\n");
    return ;
}

void in_order_node(Node *root) {
    if (root == NULL) return ;
    in_order_node(root->lchild);
    printf("%c ", root->data);
    in_order_node(root->rchild);
    return ;
}

void in_order(Tree *tree) {
    if (tree == NULL) return ;
    printf("in_order : ");
    in_order_node(tree->root);
    printf("\n");
    return ;
}

void post_order_node(Node *root) {
    if (root == NULL) return ;
    post_order_node(root->lchild);
    printf("%c ", root->data);
    post_order_node(root->rchild);
    return ;
}

void post_order(Tree *tree) {
    if (tree == NULL) return ;
    printf("post_order : ");
    post_order_node(tree->root);
    printf("\n");
    return ;
}


int main() {
    char str[1000] = {0};
    int node_num = 0;
    scanf("%[^\n]s", str);
    Tree *tree = getNewTree();
    tree->root = build(str, &node_num);
    tree->n = node_num;
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clear_tree(tree);

    return 0;
}

