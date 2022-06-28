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

int minPathSum(vector<vector<int>>& grid) {
    if (grid.size() == 0) return 0;
     
    for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i == 0 && j == 0) grid[i][j] = grid[i][j];
                else if (i == 0) grid[i][j] += grid[i][j - 1];
                else if (j == 0) grid[i][j] += grid[i - 1][j];
                else grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]); 
                //cout << grid[i][j] << endl;
            }
            
        }
    return grid[grid.size() - 1][grid[0].size() - 1];
}

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << minPathSum(grid) << endl;

    return 0;
}
