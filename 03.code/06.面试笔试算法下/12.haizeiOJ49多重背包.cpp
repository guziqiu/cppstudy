#include <iostream>
using namespace std;
#define MAX_N 100000
int dp[MAX_N];
int main() {
    
    int V, n, v, w, s;
    //第一行输入两个数𝑉、𝑛，分别代表背包的最大承重和物品种类数。
    cin >> V >> n;
    for (int i = 0; i < n; i++) {
        //𝑉𝑖、𝑊𝑖、𝑆𝑖，分别代表第 𝑖 种物品的重量、价值和数量。
        cin >> v >> w >> s;
        for (int k = 0; k < s; k++) {
            for (int j = V; j >= v; j--) {
                dp[j] = max(dp[j], dp[j - v] + w);
            }
        }
    }
    cout << dp[V] << endl;


    return 0;
}

