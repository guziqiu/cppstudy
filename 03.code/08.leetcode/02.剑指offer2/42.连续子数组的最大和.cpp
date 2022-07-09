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

int maxSubArray(vector<int>& nums) {
	int pre = 0;
	int maxAns = nums[0];
	for (const auto &x : nums) {
		pre = max(pre + x, x);
		maxAns = max(maxAns, pre);
		cout << "pre: " << pre << " ,maxAns: " << maxAns << endl;
	}

	return maxAns;
}

int main() {
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

	cout << maxSubArray(nums) << endl;

	return 0;
}
