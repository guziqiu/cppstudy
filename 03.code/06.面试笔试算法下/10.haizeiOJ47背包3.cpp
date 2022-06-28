#include <iostream>                                                                                          
using namespace std;                                                                                         
#define MAX_N 100                                                                                            
#define MAX_V 10000                                                                                          
                                                                                                             
int dp[MAX_V + 5];                                                                                
                                                                                                             
int main() {                                                                                                 
    int V, n; //背包的最大承重V和物品数n。    
    int v, w; //物品的重量v和价值w
    cin >> V >> n;//背包的最大承重v和物品数n                                                                 
    //for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];//物品从第一件开始,输入第i件物品的重量v[i]和价值w[i]    
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = V; j >= v; j--) { 
            //dp[j] = dp[j];
            if (j >= v) dp[j] = max(dp[j], dp[j - v] + w);
            //前 i 个物品，背包最大承重为 j 的情况下，得到物品的最大价值                                     
        }                                                                                                    
    }                                                                                                        
    cout << dp[V] << endl;                                                                                
    return 0;                                                                                                
}                                                                                                            
