#include <iostream>                                                                                          
using namespace std;                                                                                         
#define MAX_N 100                                                                                            
#define MAX_V 10000                                                                                          
                                                                                                             
int v[MAX_N + 5], w[MAX_N + 5];                                                                              
int dp[MAX_N + 5][MAX_V + 5];                                                                                
                                                                                                             
int main() {                                                                                                 
    int V, n;                                                                                                
    cin >> V >> n;//背包的最大承重v和物品数n                                                                 
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];//物品从第一件开始,输入第i件物品的重量v[i]和价值w[i]    
    for (int i = 1; i <= n; i++) {                                                                           
        for (int j = 1; j <= V; j++) { 
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            //dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);                                        
            //前 i 个物品，背包最大承重为 j 的情况下，得到物品的最大价值                                     
        }                                                                                                    
    }                                                                                                        
    cout << dp[n][V] << endl;                                                                                
    return 0;                                                                                                
}                                                                                                            
