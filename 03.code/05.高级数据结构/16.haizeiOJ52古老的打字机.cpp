#include <iostream>
using namespace std;

#define MAX_N 1000000
#define S(a) ((a) * (a))
long long  dp[MAX_N + 5], c[MAX_N + 5], s[MAX_N + 5];
int n, M;
long long f[MAX_N + 5];
int q[MAX_N + 5], head, tail;

double slope(int i, int j) {//求斜率
    return 1.0 * (f[i] - f[j])/(s[i] - s[j]);
}

void read() {
    cin >> n >> M;
    //第一行输入两个数字，𝑛,𝑀(1≤𝑛≤106,1≤𝑀≤104) 代表文章中字符数量和打字机单次启动的固定磨损值。
    //第二行输入 𝑛 个数字，第 𝑖 个数字代表文章中第 𝑖 个字符的磨损值 𝐶𝑖(1≤𝐶𝑖≤100)。
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        s[i] = s[i - 1] + c[i];
    }
    return ;
}

void set_dp(int i, int j) {//从i点转移到j点
    dp[i] = dp[j] + S(s[i] - s[j]) + M;
    f[i] = dp[i] + S(s[i]);
    return ;
}

long long solve()  {
    head = tail = 0;
    q[tail++] = 0;
    for (int i = 1; i <= n; i++) {
        while (tail - head >= 2 && slope(q[head + 1], q[head]) < 2 * s[i]) ++head;//
        set_dp(i, q[head]);
        while (tail - head >= 2 && slope(i, q[tail - 1]) < slope(q[tail - 2], q[tail - 1])) --tail;
        q[tail++] = i;
    }
    return dp[n];
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}

