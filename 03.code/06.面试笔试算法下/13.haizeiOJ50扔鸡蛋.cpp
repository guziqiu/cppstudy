#include <iostream>
using namespace std;

#define MAX_N 32
#define MAX_M 100000
int dp[MAX_N + 5][MAX_M + 5];
//dp[n][m]用n个鸡蛋，测 m 层楼，最坏情况下最少测dp[n][m]次

int main() {
    int n, m;
    cin >> n >> m;
    //输入两个数字 𝑛,𝑚（1≤𝑛≤32,1≤𝑚<231），代表 𝑛 个鸡蛋和 𝑚 层楼。
    for (int i = 0; i <= m; i++) dp[1][i] = i;//一个鸡蛋测i层楼,有i种方法
    for (int i = 2; i <= n; i++) {//从两个鸡蛋开始
        for (int j = 1; j <= m; j++) {//楼层
            dp[i][j] = j;
            for (int k = 1; k <= j; k++) {//
                dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1], dp[i][j - k]) + 1);
            }
        }
    }
    cout << dp[n][m] << endl;

    return 0;
}

