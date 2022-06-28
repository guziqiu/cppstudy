#include <iostream>
using namespace std;
#define MAX_N 10000
int dp[MAX_N + 5];

int main() {
    int V, n, w, v;
    //第一行为两个整数𝑁、𝑉(1≤𝑁,𝑉≤10000)，分别代表题目描述中的物品种类数量N和背包容量V。
    cin >> n >> V;
    for (int i = 0; i < n; i++) {
        cin >> v >> w;//c = v,v = w
        //第 𝑖 行两个整数𝐶𝑖、𝑉𝑖，分别代表每种物品的体积和价值。
        for (int j = v; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V] << endl;
    return 0;
}

