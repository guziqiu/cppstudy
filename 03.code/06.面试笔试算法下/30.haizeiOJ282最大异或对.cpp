#include <iostream>
using namespace std;
#define MAX_N 310000
#define BASE 31

struct Node {
    Node *next[2];
} tree[MAX_N * BASE + 5];//假如 每个都是32位，所以需要flag

int cnt = 0;
Node *getNewNode() {
    return &tree[cnt++];
}

void insert(Node *root, int x) {//插入x
    for (int i = 30; i >= 0; i--) {
        int ind = !!(x & (1 << i));
        //归一化，将(1 << i) 转换成0或1,(1 << 1) == 2,!!(1 & 2) = 0,!!(2 & 2) = 1
        //ind = (x & (1 << i)) % 2;
        if (root->next[ind] == NULL) root->next[ind] = getNewNode();
        root = root->next[ind];
    }
}

int query(Node *root, int x) {
    //求和x所能形成的最大异或和
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int ind = !(x & (1 << i));//
        if (root->next[ind]) {//判断第i位异或结果能不能为1
            ans |= (1 << i);//将ans的第i为置为1 
            root = root->next[ind];
        } else {
            root = root->next[!ind];
        }
    }
    return ans;
}

int n;
int val [MAX_N + 5];

int main() {

    cin >> n;
    int ans = 0;
    int a;
    Node *root = getNewNode();
    cin >> a;
    insert(root, a);
    n--;
    while (n --) {
        cin >> a;
        ans = max(query(root, a), ans);
        insert(root, a);
    }
    cout << ans << endl;


    return 0;
}

