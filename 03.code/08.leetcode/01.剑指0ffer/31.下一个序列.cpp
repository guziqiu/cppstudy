#include <iostream>
#include <vector>
using namespace std;

/*实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须 原地 修改，只允许使用额外常数空间。


*/

    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return ;
        int i = nums.size() - 2, j = nums.size() - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }//找到第一个升序
        if (i >= 0) {
            while (nums[j] <= nums[i]) {
                j--;
            }//找到后面的第一个比nums[i]大的值
            swap(nums[i], nums[j]);
        }

        for (int s = i + 1, e = nums.size() - 1; s < e; s++, e--) {
            swap(nums[s], nums[e]);//将后面的降序数字排列成升序
        }
        return ;
    }



int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;
}