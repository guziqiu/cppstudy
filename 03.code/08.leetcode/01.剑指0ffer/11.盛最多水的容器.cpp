#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int>& a) {
    int ans = 0;
    for (int i = 0, j = a.size() - 1; i < j;) {
        int minHeight = a[i] < a[j] ? a[i++] : a[j--];
        int area = (j - i + 1) * minHeight;
        ans = max(area, ans);
    }   

    // int ans = 0;
    // for (int i = 0; i < height.size(); i++) {
    //     for (int j = i + 1; j < height.size(); j++) {
    //         //int h = height[i] > height[j] ? height[j] : height[i];
    //         int  temp = min(height[i], height[j]) * (j - i);
    //         ans = max(temp, ans);
    //         //if (temp > max1) max1 = temp;
    //     }
    // }            
    return ans;
}
int main() {
    vector<int> height;
    height.push_back(1);
    height.push_back(8);
    height.push_back(6);
    height.push_back(2);
    height.push_back(5);
    height.push_back(4);
    height.push_back(8);
    height.push_back(3);
    height.push_back(7);
    cout << maxArea(height) << endl;

    return 0;
}
