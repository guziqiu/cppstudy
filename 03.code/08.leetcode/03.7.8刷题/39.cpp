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

vector<int> path;
vector<vector<int>> ans;

void dfs(int target, int index, vector<int> &nums)
{
	if (target < 0)
	{
		return ;
	}

	if (0 == target)
	{
		ans.push_back(path);
		return ;
	}

	for (int i = index; i < nums.size(); ++i)
	{
		if (nums[i] <= target)
		{
			path.push_back(nums[i]);
			cout << "push: " << nums[i] << " ";
			dfs(target - nums[i], i, nums);
			path.pop_back();
			cout << "pop" << endl;
		}
	}
	return ;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	dfs(target, 0, candidates);
	return ans;
}

int main() {

	vector<int> v = {2,3,6,7};

	vector<vector<int>> ans = combinationSum(v, 7);

	for (auto i : ans)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
