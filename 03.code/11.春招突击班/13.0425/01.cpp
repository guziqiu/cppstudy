#include <iostream>
using namespace std;
#define MAX_N 100000

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
    int leavl;
} Node;
int ans = 0;
Node *init(int _data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = _data;
    p->lchild = p->rchild = NULL;
    p->leavl = 1;
    return p;
}
Node *getNewNode(int _data, int leavl) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = _data;
    p->lchild = p->rchild = NULL;
    p->leavl = leavl;
    ans = leavl;
    return p;
}

Node *insert(Node *root, int val, int leval) {
    // cout << leval << endl;
    if (root == NULL) return getNewNode(val, leval);
    if (root->data == val) return root;
    if (root->data > val) {
        root->lchild = insert(root->lchild, val, root->leavl + 1);
    }
    else {
        root->rchild = insert(root->rchild, val, root->leavl + 1);
    }
    return root;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->rchild);
    clear(root->lchild);
    free(root);
    return ;
}
int tdepth(int* arr, int arrLen) {
    int ind = 1; // 1 (2  3) (4,5  6,7)
    Node *root = init(arr[0]);
    for (int i = 1; i < arrLen; i++) {
        insert(root, arr[i], 2);
    }
    clear(root);
    return ans;
        
}

int main() {
    int arr[] = {2,3,8,9,4,5,1,7};
    cout << tdepth(arr, 8);
    return 0;
}

