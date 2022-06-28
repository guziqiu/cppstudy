#include <iostream>
#include <climits>
using namespace std;

//海贼OJ222

#define MAX_N 10000

struct {
    int max_num;
    int l,r;
} tree[MAX_N << 2];
int arr[MAX_N + 5];

void update(int ind) {//更新结点的最大值
    tree[ind].max_num = max(tree[ind << 1].max_num, tree[ind << 1 | 1].max_num);
    return ;
}

void build_tree(int ind, int l, int r) {//创建线段树,在ind上插入l，r
    tree[ind].l = l;
    tree[ind].r = r;
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

void modify(int ind, int k, int val) {
    if (tree[ind].l == tree[ind].r) {
        tree[ind].max_num = val;
        return ;
    }
    int mid = (tree[ind].l + tree[ind].r) >> 1;
    if (k <= mid ) {
        modify(ind << 1, k, val);
    } else {
        modify(ind << 1 | 1, k, val);
    }
    update(ind);
    return ;
}

int Query(int ind, int x, int y) {//查询
    if (tree[ind].l >= x && tree[ind].r <= y) {//要查找的值在这个根的
        return tree[ind].max_num;
    }
    int ans = INT_MIN;
    int mid = (tree[ind].l + tree[ind].r) >> 1;
    if (mid >= x) {//在左子树中查找
        ans = max(ans, Query(ind << 1, x, y));
    }
    if (mid < y) {//在右子树中查找
        ans = max(ans, Query(ind << 1 | 1, x, y));
    }
    return ans;
}



int main() {

    int m, n;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    build_tree(1, 1, n);
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
        case 1: modify(1, b, c); break;
        case 2: {
                    if (b > c) {
                        cout << "-2147483648" << endl;
                        break;
                    }
                    cout << Query(1, b, c) << endl;
                } break;
        }
    }



    return 0;
}

