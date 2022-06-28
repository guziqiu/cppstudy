#include <iostream>
using namespace std;
struct {
    long long sum; 
    long long flag; 
} tree[20000];

long long arr[10000 + 5];
 

void flag1(long long index, long long left, long long right) {
    if (tree[index].flag) { 
        long long mid = (left + right) >>  1;
        long long value = tree[index].flag;
        tree[index << 1].sum += value * (mid - left + 1);
        tree[index << 1].flag += value;
        tree[index << 1 | 1].sum += value * (right - mid);
        tree[index << 1 | 1].flag += value;
        tree[index].flag = 0;
    }
    return ;
}

void xtree(long long index, long long left, long long right) {//线段树
    if (left == right) {
        tree[index].sum = arr[left];
        return ;
    }
    long long mid = (left + right) >>  1;
    xtree(index << 1, left, mid);
    xtree(index << 1 | 1, mid + 1, right);
    tree[index].sum = tree[index << 1].sum + tree[index << 1 | 1].sum;
    return ;
}
void add(long long index, long long left, long long right, long long x, long long y, long long value) {
    //[1, n] [b,c] 将数组 [𝑏,𝑐]区间内的数字加上 𝑑

    if (x <= left && right <= y) { 
        tree[index].sum += value * (right - left + 1);
        tree[index].flag += value; 
        return ;
    }
    flag1(index, left, right); 
    long long mid = (left + right) >>  1;
    if (mid >= x) add(index << 1, left, mid, x, y, value);
    if (mid < y) add(index << 1 | 1, mid + 1, right, x, y, value);
     
    tree[index].sum = tree[index << 1].sum + tree[index << 1 | 1].sum;
    return ;
}

long long query(long long index, long long left, long long right, long long x, long long y) {//询问 [𝑏,𝑐] 区间内的和值
    if (x <= left && right <= y) {//要查询的区间[x, y]在[left, right]范围内
        return tree[index].sum;
    }
    flag1(index, left, right);
    long long mid = (left + right) >>  1;
    long long sum = 0;
    if (mid >= x)    sum += query(index << 1, left, mid, x, y);
    if (mid < y) sum += query(index << 1 | 1, mid + 1, right, x, y);
    return sum;
}




int main() {
    long long n, m;
    scanf("%lld%lld", &n, &m);//第一行输入两个整数 𝑛,𝑚(1≤𝑛≤10000，3≤𝑚≤100000)，分别代表数组大小和操作数。
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", arr + i);//第二行包含 𝑛个整数，代表数组中相应的数字，数字大小不会超过 𝑖𝑛𝑡 表示范围。
    }
    xtree(1, 1, n);
    long long a, b, c, d;
    for (long long i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        switch (a) {
        case 1: {
                    scanf("%lld", &d);
                    add(1, 1, n, b, c, d);
                }break;
        case 2: {
                    if (b > c) {
                    printf("0\n");
                    break;
                }
                printf("%lld\n", query(1, 1, n, b, c));
            } break;
        }
    }


    return 0;
}

