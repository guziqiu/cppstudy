#include <iostream>

struct tree {
    long long sum;
    long long flag;
} tree[20000];
long long arr[10000 + 5];

void xtree(long long index, long long left, long long right) {//线段树
    if (left == right) {//
        tree[index].sum = arr[left];
        return ;
    }
    long long mid = (left + right) / 2;
    xtree(index * 2, left, mid);
    xtree(index * 2 + 1, mid + 1, right);
    tree[index].sum = tree[index * 2].sum + tree[index * 2 + 1].sum;
    return ;
}

void flagto0(long long i, long long left, long long right) {//[i]
    if (tree[i].flag) {
        long long mid = (left + right) / 2;
        long long value = tree[i].flag;
        tree[i * 2].sum += value * (mid - left + 1);
        tree[i * 2].flag += value;
        tree[i * 2 + 1].sum += value * (right - mid);
        tree[i * 2 + 1].flag += value;
        tree[i].flag = 0;
    }
    return ;
}
void add(long long i, long long left, long long right, long long b, long long c, long long d) {//[1, n] [b,c] 将数组 [𝑏,𝑐]区间内的数字加上 𝑑
    long long n = right;
     // left == 1
    if (b <= left && n <= c) {
        tree[i].sum += d * (n - left + 1);
        tree[i].flag += d;
        return ;
    }
    //处理懒标记
    flagto0(i, left, n);
    long long mid = (left + n) / 2;
    if (mid < c) add(i << 1 | 1, mid + 1, n, b, c, d);//
    if (mid >= b) add(i << 1, left, mid, b, c, d);

    tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum; 

}

long long query(long long i, long long left, long long right, long long b, long long c) {//询问 [𝑏,𝑐] 区间内的和值
    long long n = right;
    if (b <= left && right <= c) return tree[i].sum;
    flagto0(i, left, right);
    long long mid = (left + n) >> 1;
    long long sum = 0;
    if (mid < c) sum += query(i << 1 | 1, mid + 1, n, b, c);//
    if (mid >= b) sum += query(i << 1, left, mid, b, c);
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
        switch(a) {
            case 1: {
                scanf("%lld", &d);
                add(1, 1, n, b, c, d);
            } break;
            case 2: {//当 𝑎=2 时，接下来输入 𝑏,𝑐，输入代表询问 [𝑏,𝑐] 区间内的和值 ( 1≤𝑏,𝑐≤𝑛)，当 𝑏>𝑐 时，输出 0。
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

