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
	if (grid.size() == 0)
	{
		return 0;
	}

	// 从gird[grid.size() - 1][grid[0].size() - 1]往前看

	// 先解决没有左边和上边的网格
	for (int i = 1; i < grid[0].size(); ++i)
	{
		grid[0][i] += grid[0][i - 1];
		// cout << grid[0][i] << " ";
	}

	for (int i = 1; i < grid.size(); ++i)
	{
		grid[i][0] += grid[i - 1][0];
		cout << grid[i][0] << endl;
	}

	// 计算有左边和上边的网格
	for (int i = 1; i < grid.size(); ++i)
	{
		for (int j = 1; j < grid[0].size(); ++j)
		{
			grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	return *grid.rbegin()->rbegin();
}


int main() {

	vector<vector<int>> v = {{1,2,3},{4,5,6}};
	cout << minPathSum(v) << endl;

	return 0;
}
