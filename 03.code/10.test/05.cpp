#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int color; 
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->data = 0;
    NIL->color = 1;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int _data) {
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = _data;
    root->color = 0;
    root->lchild = root->rchild = NIL;
    return root;
}

int has_red_child(Node *root) { 
    return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *left(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}
 

Node *__insert(Node *root, int value) {
    if (root == NIL) return getNewNode(value);
    if (root->data == value) return root;
    if (value < root->data) root->lchild = __insert(root->lchild, value);
    else root->rchild = __insert(root->rchild, value);
    if (!has_red_child(root)) return root; 
    int flag = 0;
    if (root->lchild->color == 0 && root->rchild->color == 0 &&  (has_red_child(root->lchild) || has_red_child(root->rchild))) {
        root->color = 0;
        root->lchild->color = root->rchild->color = 1;
        return root;
    } 
    if (root->lchild->color == 0 && has_red_child(root->lchild))flag = 1;
    if (root->rchild->color == 0 && has_red_child(root->rchild)) flag = 2;
    if (flag == 0) return root;
    if (flag == 1) {
        if (root->lchild->rchild->color == 0) root->lchild = left(root->lchild);
        root = right(root);
    } else {//
        if (root->rchild->lchild->color == 0) root->rchild = right(root->rchild);
        root = left(root);
    }
    root->color = 0; 
    root->lchild->color = root->rchild->color = 1;
    return root;
}

Node *insert(Node *root, int data) {
    root = __insert(root, data);
    root->color = 1;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;
    if (has_red_child(root)) {
        if (root->lchild->color == 0) {
            root->color = 0;
            root = right(root);;
            root->color = 1;
            root->rchild = erase_maintain(root->rchild);
        } else {
            root->color = 0;
            root = left(root);
            root->color = 1;
            root->lchild = erase_maintain(root->lchild);
        }
    } else {
        if (root->lchild->color == 2) {
            if (!has_red_child(root->lchild)) {
                root->color += 1;
                root->lchild->color -= 1;
                root->rchild->color -= 1;
            } else {
                root->lchild->color = 1;
                if (root->rchild->rchild->color != 0) {
                    root->rchild->color = 0;
                    root->rchild = right(root->rchild);
                    root->rchild->color = 1;
                }
                root->rchild->color = root->color;
                root = left(root);
                root->rchild->color = root->lchild->color = 1;
            }
        } else if (root->rchild->color == 2) {
            if (!has_red_child(root->lchild)) {
                root->color += 1;
                root->lchild->color -= 1;
                root->rchild->color -= 1;
            } else {
                root->rchild->color = 1;
                if (root->lchild->lchild->color != 0) {
                    root->lchild->color = 0;
                    root->lchild = left(root->lchild);
                    root->lchild->color = 1;
                }
                root->lchild->color = root->color;
                root = right(root);
                root->rchild->color = root->lchild->color = 1;
            }
        }
    }
    return root;
}

Node *__erase(Node *root, int value) {
    if (root == NIL) return NIL;
    if (value < root->data) root->lchild = __erase(root->lchild, value);
    else if (value > root->data) root->rchild = __erase(root->rchild, value);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            temp->color += root->color;
             
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->data = temp->data;
            root->lchild = __erase(root->lchild, temp->data);
        }
    }
    root = erase_maintain(root);
    return root;
}

Node *erase(Node *root, int value) {
    root = __erase(root, value);
    root->color = 1;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void print(Node *root) {
    printf("%d %d %d %d\n",
        root->data, root->color,
        root->lchild->data,
        root->rchild->data
    );
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    output(root->lchild);
    print(root);
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
            case 3: output(root);
        }
         
    }


    return 0;
}

