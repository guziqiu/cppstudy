#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<algorithm>
using namespace std;
 
 
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums[i + 1] && i < nums.size()) return nums[i]; 
        }
    }
 
int main() {
    vector<int> v;
    v.push_back(1);
    cout << v[0] << " " << v.size() << endl;
    return 0;
    cout << max(1, 2) << endl;


    return 0;
}