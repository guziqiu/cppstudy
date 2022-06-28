#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int _data) {
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = _data;
    root->lchild = root->rchild = NULL;
    return root;
}

Node *insert(Node *root, int value) {
    if (root == NULL) return getNewNode(value);
    if (root->data == value) return root;
    if (value < root->data) {
        root->lchild = insert(root->lchild, value);
    }
    else root->rchild = insert(root->rchild, value);
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp && temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int val) {
    if (root == NULL) return NULL;
    if (val < root->data) {
        root->lchild = erase(root->lchild, val);
    } else if (val > root->data) {
        root->rchild = erase(root->rchild, val);
    } else {
        if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else  {
            Node *temp = predecessor(root);
            root->data = temp->data;
            root->lchild = erase(root->lchild, temp->data);
        }
    }
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
    printf("%d ", root->data);
    output(root->rchild);
}
int main() {
     Node *root = NULL;
    int arr[10] = { 8, 9, 10, 3, 2, 1, 6, 4, 7, 5 };
    for (int i = 0; i < 10; i++) {
        printf("insert : %d ", arr[i] );
        root = insert(root, arr[i]);
        printf("\n");
        output(root);
        printf("\n-----------\n");
        
    }

    for (int i = 0; i < 10; i++) {
        printf("delete : %d ", arr[i] );
        root = erase(root, arr[i]);
        printf("\n");
        output(root);
        printf("\n-----------\n");
        
    }
    
    return 0;
}

