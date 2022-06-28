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
int search(vector<int>& nums, int target) {
	if (nums.size() == 0)
	{
		return 0;
	}
	// 双指针
	int ans = 0;
	int r = nums.size() - 1;
	// 二分查找
	int l = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (nums[mid] >= target)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	while (nums[l++] == target)
	{
		++ans;
	}
	return ans;
}

int main() {
	vector<int> nums({1});

	cout << search(nums, 1) << endl;
	return 0;
}

  