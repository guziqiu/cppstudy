#include <iostream>
using namespace std;

#define MAX_N 10000
typedef long long intl;
intl flag = 0;
struct {
    intl sum;//和值
    intl tag;//懒标记
} tree[MAX_N << 2];

intl arr[MAX_N + 5];

void update(intl ind) {
    tree[ind].sum = tree[ind << 1].sum + tree[ind << 1 | 1].sum;
    //tree[ind].sum = tree[ind * 2].sum + tree[ind * 2 + 1].sum;
    return ; 
}

void down(intl index, intl left, intl right) {
    if (tree[index].tag) {//懒标记下沉左右子树
        intl mid = (left + right) >>  1;
        intl value = tree[index].tag;
        tree[index << 1].sum += value * (mid - left + 1);
        tree[index << 1].tag += value;
        tree[index << 1 | 1].sum += value * (right - mid);//right - (mid + 1)+1
        tree[index << 1 | 1].tag += value;
        tree[index].tag = 0;
    }
    return ;
}

void build_tree(intl index, intl left, intl right) {
    if (left == right) {
        tree[index].sum = arr[left];
        return ;
    }
    intl mid = (left + right) >>  1;
    build_tree(index << 1, left, mid);
    build_tree(index << 1 | 1, mid + 1, right);
    update(index);
    return ;
}
void modify(intl index, intl left, intl right, intl x, intl y, intl value) {
    flag && printf("modify(%lld, %lld, %lld) : %lld, %lld, %lld, %lld\n",
                       x, y, value, index, left, right, tree[index].sum
    );
    //从根节点tree[index]开始查询，根节点的区间是[left, right],找到区间[x, y],把[x, y]区间上的值加上value
    if (x <= left && right <= y) {//待操作区间在包含区间的范围内，即要修改的区间比根节点区间大
        tree[index].sum += value * (right - left + 1);
        tree[index].tag += value;//懒标记，皇帝给农民发放粮食，县令不放
        return ;
    }
    down(index, left, right);//懒标记下沉，皇帝要微服私访，县令下发粮食
    intl mid = (left + right) >>  1;
    if (mid >= x) {
        modify(index << 1, left, mid, x, y, value);
    }
    if (mid < y) {
        modify (index << 1 | 1, mid + 1, right, x, y, value);
    }
    update(index);
    return ;
}

intl Query(intl index, intl left, intl right, intl x, intl y) {
    if (x <= left && right <= y) {//要查询的区间[x, y]在[left, right]范围内
        return tree[index].sum;
    }
    down(index, left, right);
    intl mid = (left + right) >>  1;
    intl ans = 0;
    if (mid >= x) {
        ans += Query(index << 1, left, mid, x, y);
    }
    if (mid < y) {
        ans += Query(index << 1 | 1, mid + 1, right, x, y);
    }
    return ans;
}




int main() {
    intl n, m;
    scanf("%lld%lld", &n, &m);
    for (intl i = 1; i <= n; i++) {
        scanf("%lld", arr + i);
    }
    build_tree(1, 1, n);
    intl a, b, c, d;
    for (intl i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        switch (a) {
        case 1: {
                    scanf("%lld", &d);
                    modify(1, 1, n, b, c, d);
                }break;
        case 2: {
                    if (b > c) {
                        cout << "0" << endl;
                        break;
                    }
                    cout << Query(1, 1, n, b, c) << endl;//从根节点开始查询，根节点的范围是[1,n],查询[b,c]区间范围内的值
                }break;
        }
    }


    return 0;
}

