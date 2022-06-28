#include <iostream>
using namespace std;
#define MAX_N 100000
int dp[MAX_N];
int main() {
    
    int V, n, v, w, s;
    //第一行输入两个数𝑉、𝑛，分别代表背包的最大承重和物品种类数。
    cin >> V >> n;
    for (int i = 0; i < n; i++) {
        //v、w、s代表物品的重量、价值和数量。
        cin >> v >> w >> s;
        for (int k = 1; s; k *= 2) {//当前一共有多少物品
            if (k > s) k = s;
            s -= k;//减去物品加上的数量
            for (int j = V; j >= k * v; j--) {//当前这一堆的总重量为k * v
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
            }
        }
    }
    cout << dp[V] << endl;


    return 0;
}

