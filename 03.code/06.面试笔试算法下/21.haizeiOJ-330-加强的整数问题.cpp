#include <iostream>
using namespace std;
#define MAX_N 100000
#define lowbit(x) (x & -x)
long long c[2][MAX_N + 5];//差分数组

void add(long long k, long long i, long long x, long long n) {
    //在c[k][i]的位置加x
    while (i <= n) {
        c[k][i] += x;
        i += lowbit(i);
    }
    return ;
}

long long query(long long k, long long i) {
    //查询c[k][i]的前缀和
    long long sum = 0;
    while (i) {
        sum += c[k][i];
        i -= lowbit(i);
    }
    return sum;
}

long long S(long long i) {//S[i]前i项和
    return (i + 1) * query(0, i) - query(1, i);
}

void modify(long long i, long long x, long long n) {//在c[][i]位置上加上x
    add(0, i, x, n);
    add(1, i, i * x, n);
    return ;
}

int main() {
    long long m, n;
    //第一行包含两个整数𝑁,𝑀(1≤𝑁,𝑀≤100000)，代表序列的长度和询问的次数.
    //cin >> n >> m;
    scanf("%lld%lld", &n, &m);
    //第二行包含𝑁个整数，表示初始的序列𝐴(−1000000000≤𝐴𝑖≤1000000000)。
    for (long long i = 1, pre = 0, a; i <= n; i++) {
        //cin >> a;
        scanf("%lld", &a);
        modify(i, a - pre, n);
        pre = a;
    }
    char s[10];
    for (long long i = 0, l, r, d; i < m; i++) {
        //cin >> s;
        scanf("%s", s);
        switch (s[0]) {
        case 'C': {//"C a b c"表示给[a, b]区间中的值全部增加c (-10000 ≤ c ≤ 10000)。
                      //cin >> l >> r >> d;
                      scanf("%lld%lld%lld", &l, &r, &d);
                      modify(l, d, n);
                      modify(r + 1, -d, n);
                  }break;
        case 'Q': {//"Q a b" 询问[a, b]区间中所有值的和。
                      //cin >> l >> r;
                      scanf("%lld%lld", &l, &r);
                      printf("%lld\n", S(r) - S(l - 1));
                      //cout << (S(r) - S(l - 1)) << endl;
                  }break;
        }
    }

    return 0;
}

