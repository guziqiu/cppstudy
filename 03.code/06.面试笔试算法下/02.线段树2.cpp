#include <iostream>
#include <climits>
using namespace std;

//海贼OJ222

#define MAX_N 10000

struct {
    int max_num;//子树的和值
} tree[MAX_N << 2];
int arr[MAX_N + 5];

void update(int ind) {//更新结点的和值
    tree[ind].max_num = max(tree[ind << 1].max_num, tree[ind << 1 | 1].max_num);
    return ;
}

void build_tree(int ind, int l, int r) {//创建线段树,在ind上插入l，r
    if (l == r) {//l==r，l、r各代表一个值，不能再分裂
        tree[ind].max_num = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build_tree(ind * 2, l, mid);
    build_tree(ind * 2 + 1, mid + 1, r);
    update(ind);
    return ;
}

void modify(int ind, int l, int r, int k, int val) {//在tree[ind](ind当前节点位置）维护的区间[l, r],上将tree[k]的值修改为val、
    if (l == r) {
        tree[ind].max_num = val;
        return ;
    }
    int mid = (l + r) >> 1;
    if (k <= mid ) {
        modify(ind << 1, l, mid, k, val);
    } else {
        modify(ind << 1 | 1, mid + 1, r, k, val);
    }
    update(ind);
    return ;
}

int Query(int ind, int l, int r, int x, int y) {//查询
    if (l >= x && r <= y) {//要查找的值在这个根的
        return tree[ind].max_num;
    }
    int ans = INT_MIN;
    int mid = (l + r) >> 1;
    if (mid >= x) {//在左子树中查找
        ans = max(ans, Query(ind << 1, l, mid, x, y));
    }
    if (mid < y) {//在右子树中查找
        ans = max(ans, Query(ind << 1 | 1, mid + 1, r, x, y));
    }
    return ans;
}



int main() {

    int m, n;
    scanf("%d%d", &n, &m);//n,数组长度，m,操作数
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    build_tree(1, 1, n);//初始化线段树tree,根节点的范围是[1, n]
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
        case 1: modify(1, 1, n, b, c); break;//在根节点[1, n]上修改tree[b]的值为c
        case 2: {
                    if (b > c) {
                        cout << "-2147483648" << endl;
                        break;
                    }
                    cout << Query(1, 1, n, b, c) << endl;//在根节点tree[1,n]上查找[b, c]区间上的和值
                } break;
        }
    }



    return 0;
}

