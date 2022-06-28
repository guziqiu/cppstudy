#include <iostream>
#include <cmath>
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
int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.size() == 1) return triangle[0][0];
    vector<vector<int>> init(triangle.size(), vector<int>(triangle.size(), INT32_MAX)); // 记录每一层的值
    init[0][0] = triangle[0][0];
    int ans = INT32_MAX;
    for (int i = 0; i < triangle.size() - 1; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            init[i + 1][j] = min(init[i][j] + triangle[i + 1][j], init[i + 1][j]);
            init[i + 1][j + 1] = min(init[i][j] + triangle[i + 1][j + 1], init[i + 1][j + 1]);
        }
    }
    for (int j = 0,i = init.size() - 1; j < init[i].size(); j++) {
        ans = min(ans, init[i][j]);
    }
     
    return ans;
}
int func(vector<vector<int>>& triangle, int i, int j) {
    if (i == triangle.size()) return 0;
    return min(func(triangle, i + 1, j), func(triangle, i + 1, j + 1)) + triangle[i][j];
}
int minimumTotal2(vector<vector<int>>& triangle) {
    return func(triangle, 0, 0);
}

int minimumTotal3(vector<vector<int>>& triangle) {
    int ans = INT64_MAX;
    vector<int> minNum(triangle.size());
   for (int i = 0; i < triangle.size() - 1; i++) {
       for (int j = 0; j < triangle.size() - 1; j++) {
            minNum[i] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
       }
    }
}

int main() {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    //triangle = {{-10}};
    cout << minimumTotal2(triangle) << endl;;

    return 0;
}
