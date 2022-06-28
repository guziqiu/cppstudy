#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>  ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[i + 1]) continue;
            //nums.erase(nums[i]);
        }
        return ans;
}

int main() {
     
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums = findDisappearedNumbers(nums);
    for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}