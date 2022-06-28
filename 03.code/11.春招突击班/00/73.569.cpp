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

int sum = 0;
int v[10000 + 5]; // 质量 整数
double c[10000 + 5]; // 浓度 实数
int V;
double C;
void funcP(double v2, int c2, int i) {
    sum++;
    v[sum] = v[sum - 1] + v2;
    c[sum] = (c[sum - 1] + c2) / (v[sum - 1] + v2) * 100;
    C = c[sum], V =v[sum];
    return ;
}

void funcZ(int i) {
    sum--;
    if (sum < 0)  sum = 0;
    C = c[sum], V = v[sum];
    return ;
}

int main() {
    int n;
    cin >> v[0] >> c[0];// 初始质量和浓度 𝑉0、𝐶0%
    cin >> n;
    

    for (int i = 0; i < n; i++) {
        char t;
        cin >> t;
        double v1; 
        int c1;
        if (t == 'P') {
            cin >> v1 >> c1;
            funcP(v1, c1, i);        
        } else {
            funcZ(i);
        }
        printf("%d %.5f\n", V, C); 
    }




    return 0;
}

