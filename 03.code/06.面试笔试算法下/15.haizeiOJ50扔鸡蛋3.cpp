#include <iostream>
using namespace std;

#define MAX_N 32
#define MAX_K 100000
long long dp[MAX_N + 5][MAX_K + 5];
//dp[n][m]用n个鸡蛋，测 m 层楼，最坏情况下最少测dp[n][m]次

int solve(int n,int m) {
    if (n == 1) return m;
    for (int i = 1; i <= MAX_K; i++) dp[1][i] = i;//1个鸡蛋测i层楼有i种方法
    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= MAX_K; k++) {
            dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1] + 1;
        }
    }
    int k = 1;
    while(dp[n][k] < m) k++;//n个鸡蛋扔k次不足以测m层楼的时候增加k

    return k;
}


int main() {
    int n, m;
    cin >> n >> m;
    //输入两个数字 𝑛,𝑚（1≤𝑛≤32,1≤𝑚<231），代表 𝑛 个鸡蛋和 𝑚 层楼。
    cout << solve(n, m) << endl;
    return 0;
}

