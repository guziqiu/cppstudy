#include <iostream>
using namespace std;
#define MAX_N 200000

struct Node {
    Node *next[2];
} tree[MAX_N * 50 + 5]; 

int cnt = 0;
Node *getNewNode() {
    return &tree[cnt++];
}

void insert(Node *root, int n) { 
    for (int i = 30; i >= 0; i--) {//31
        int index = !!(n & (1 << i));     
        if (root->next[index] == NULL) root->next[index] = getNewNode();
        root = root->next[index];
    }
}

int query(Node *root, int n) {
    
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int index = !(n & (1 << i));//
        if (root->next[index]) { 
            ans |= (1 << i); 
            root = root->next[index];
        } else {
            root = root->next[!index];
        }
    }
    return ans;
}



int main() {
    int n;

    scanf("%d", &n);
    int ans = 0;
    int val;
    Node *root = getNewNode();
    scanf("%d", &val);
    insert(root, val);
    n--;
    while (n--) {
        scanf("%d", &val);
        ans = max(query(root, val), ans);
        insert(root, val);
    }
    printf("%d", ans);


    return 0;
}
