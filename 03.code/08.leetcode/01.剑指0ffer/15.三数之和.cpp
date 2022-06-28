#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<vector<int> > threeSum(vector<int>& nums) {
    
    vector<vector<int> > ans;
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < nums.size(); j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            for (int k = j + 1; k < nums.size(); k++) {
                if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> v1;
                    v1.push_back(nums[i]);
                    v1.push_back(nums[j]);
                    v1.push_back(nums[k]);
                    ans.push_back(v1);
                }  
            }
        }
    }
    //printf("]");
    return ans;
}
 
 vector<vector<int> > threeSum3(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        //[a, b, c]
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            if (nums[first] > 0) break;//如果第一个数字>0,则三个数字之和就不可能等于0
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) continue;
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) --third;
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) break;
                if (nums[second] + nums[third] == target) {
                    vector<int> v1;
                    v1.push_back(nums[first]);
                    v1.push_back(nums[second]);
                    v1.push_back(nums[third]);
                    ans.push_back(v1);
                }
            }
        }
        return ans;
    }
 
vector<vector<int> > threeSum4(vector<int>& nums) {
        vector<vector<int> > ans;
        if(nums.size() < 3) return ans;//特判，对于数组长度n，如果数组为null 或者数组长度小于3，返回[]。
        sort(nums.begin(), nums.end());//对数组进行排序。
        //if(nums[0] > 0) return ans;//若 nums[i]>0：因为已经排序好，所以后面不可能有三个数加和等于0，直接返回结果
        
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) break;//若 nums[i]>0：因为已经排序好，所以后面不可能有三个数加和等于0，直接返回结果       
            int left = i + 1, right = nums.size() - 1;
            while(left < right){//令左指针 L = i + 1，右指针 R = n - 1，当 L < R 时，执行循环：
                if(nums[i] + nums[left] > 0 - nums[right]) {//若和大于0，说明nums[R] 太大，R左移
                    right--;
                }
                else if(nums[i] + nums[left] < 0 - nums[right] ) {//若和小于0，说明nums[L] 太小，L右移
                    left++;
                }
                else{//当 nums[i]+nums[L]+nums[R]==0，执行循环，
                //判断左界和右界是否和下一位置重复，去除重复解。
                //并同时将L,R 移到下一位置，寻找新的解
                    vector<int> v1;
                    v1.push_back(nums[i]);
                    v1.push_back(nums[left]);
                    v1.push_back(nums[right]);
                    ans.push_back(v1);
                    // 相同的left和right不应该再次出现，因此跳过
                    while(left < right && nums[left] == nums[left+1])
                        left++;
                    while(left < right && nums[right] == nums[right-1])
                        right--;
                    left++;
                    right--;
                }
            }
            // 避免nums[i]作为第一个数重复出现
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }


int main() {
    //nums = [-1,0,1,2,-1,-4]
    vector<int> v;
    //cout  << "..." << endl;
    v.push_back(-1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(-1);
    v.push_back(-4);

    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
     
    cout  << "..." << endl;
    vector<vector<int> > vn = threeSum4(v);
    printf("[");
    for (int i = 0; i < vn.size(); i++) {
        printf("[");
        for (int j = 0; j < vn[i].size(); j++) {
            j && cout << ",";
            cout << vn[i][j];
        }
        cout << "]" ;
    }
    cout << "]" << endl;
     
    

    return 0;
}

