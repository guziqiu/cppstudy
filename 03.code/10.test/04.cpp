#include <iostream>
using namespace std;

struct Node {
    Node *next[2];
} tree[10000 * 31 + 5];
int cnt = 0;
Node *getNewNode() {
    return &tree[cnt++];
}
void insert(Node *root, int n) {
    for (int i = 30; i >= 0; i--) {
        int ind = !!(n & (1 << i));
        if (root->next[ind] == NULL) root->next[ind] = getNewNode();
        root = root->next[ind];
    }
    
    //cout << "1"  << endl;
}

int query(Node *root, int n) {
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int ind = !(n & (1 << i));
        if (root->next[ind]) {
            ans |= (1 << i);
            root = root->next[ind];
        } else {
            root = root->next[ind];
        }
    }
    cout << "2"  << endl;
    return ans;
}


int main() {
    //第一行一个整数 𝑁，第二行 𝑁 个正整数 𝐴1−𝐴𝑁。
    int n;
    scanf("%d", &n);
    int ans = 0;
    Node *root = &tree[cnt++];
    int val;
    scanf("%d", &val);
    insert(root, val);
    n--;
    //cout << "1"  << endl;
    while (n--) {
        scanf("%d", &val);
        ans = max(query(root, val), ans);
        insert(root, val);
        cout    << endl;
    }
    printf("%d\n", ans);
    
    return 0;
}

