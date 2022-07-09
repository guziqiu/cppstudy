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
vector<int> spiralOrder(vector<vector<int> >& matrix) {
	if (matrix.empty())
	{
		return {};
	}
	int left   = 0;                      // 左边界
	int right  =  matrix[0].size() - 1;  // 右边界
	int top    = 0;                      // 上边界
	int bottom = matrix.size() - 1;      // 下边界

	/*
	------->------|
	|             |
	|             |
	^             v
	|             |
	|------<------|
	*/
	vector<int> ans;

	while(true) {
		// left -> right
		for (int i = 0; i <= right; ++i) ans.push_back(matrix[top][i]);
		++top;
		if (top > bottom) break;

		// top -> bottom
		for (int i = top; i <= bottom; ++i) ans.push_back(matrix[i][right]);
		--right;
		if (right < left) break;

		// right -> left
		for (int i = right; i >= left; --i) ans.push_back(matrix[bottom][i]);
		--bottom;
		if (bottom < top) break;

		// bottom -> top
		for (int i = bottom; i >= top; --i) ans.push_back(matrix[i][left]);
		++left;
		if (left > right) break;
	}
	return ans;
}

int main() {


	vector<vector<int> > matrix;
	vector<int> a({1, 2, 3});
	vector<int> b({4, 5, 6});
	vector<int> c({7, 8, 9});

	matrix.push_back(a);
	matrix.push_back(b);
	matrix.push_back(c);
	vector<int> ans = spiralOrder(matrix);

	for (int i = 0; i < ans.size(); ++i)
	{
		// for (int j = 0; j < ans[i].size(); ++j)
		// {
			cout << ans[i] << " ";
		// }
		
	}
	cout << endl;


	return 0;
}
