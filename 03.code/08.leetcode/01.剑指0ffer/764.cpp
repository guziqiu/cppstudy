#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int func(vector<int>& cost, int i, vector<int> &ans) {
    if (i == 0 || i == 1) {
        ans[i] = cost[i];
        return ans[i];
    }
    ans[i] = min(func(cost, i - 1, ans) , func(cost, i - 2, ans)) + cost[i];
    cout << "i = " << ans[i] << endl;
    return ans[i]; 
}

int minCostClimbingStairs(vector<int>& cost) {
    cost.push_back(0);
    int size = cost.size();
    vector<int> ans(size, -1);
    return func(cost, size - 1, ans);
}
// int dp[1000 + 5] = {0};
// int minCostClimbingStairs2(vector<int>& cost) {
//     cost.push_back(0);
//     dp[0] = cost[0];
//     dp[1] = cost[1];
//     for (int i = 2; i < cost.size(); i++) {
//         dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//     }
//     return dp[cost.size() - 1];
// }
int dp[3] = {0};
int minCostClimbingStairs3(vector<int>& cost) {
    cost.push_back(0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < cost.size(); i++) {
        dp[i % 3] = min(dp[(i - 1) % 3], dp[(i - 2) % 3]) + cost[i];
    }
    return dp[(cost.size() - 1) % 3];
} // 10 15 30 0 + 15 
int main() {
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs3(cost) << endl;    
    return 0;
}

