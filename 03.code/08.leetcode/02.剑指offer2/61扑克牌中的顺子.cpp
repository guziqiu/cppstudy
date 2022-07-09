#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
bool isStraight(vector<int>& nums) {
	// set<int> ans;
	// int zero = 0;
	
	// for (int i : nums) {
	// 	if (ans.find(i) != ans.end()) return false;
	// 	if (i) ans.insert(i);

	// }

	// return ((*ans.rbegin() - *ans.begin()) < 5);

	//用一个桶，用来计数
	int bucket[14] = {0}; // 因为有14张牌
	for (int num : nums){
		//如果出现重复的牌，且该牌不是大小王0，则返回false。
		if (num != 0 && bucket[num] > 0) return false;
		//桶计数
		bucket[num]++;
	}
	//用双指针定位到最大的牌和最小的牌
	int left = 1;
	int right = 13;
	while (bucket[left] == 0) left++;
	while (bucket[right] == 0) right--;
	return right - left + 1 <= 5;
}

int main() {
	vector<int> nums = {4,7,5,9,2};
	// vector<vector<int> > num = {{1,2,3,4,5}, {123}};
	cout << isStraight(nums) << endl;;
	return 0;
}
