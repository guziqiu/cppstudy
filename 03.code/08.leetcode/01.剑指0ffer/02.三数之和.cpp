#include <iostream>
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

void threesum(vector<int> &num) {
    if (num.size() < 3) return ;
    vector<vector<int> > ans;
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++) {
        int left = i + 1, right = num.size() - 1;
        while (left < right) {
            if (num[i] + num[left] + num[right] == 0) {
                cout << "[" << num[i] << ", " << num[left] << ", " << num[right] << "]" << endl;
                while(left < right && num[left] == num[left+1]) left++;
                while(left < right && num[right] == num[right-1]) right--;
                left++, right--;
            }
            if (num[i] + num[left] + num[right] > 0) right--;
            if (num[i] + num[left] + num[right] < 0) left++;
            cout << endl;
        }
        while(i + 1 < num.size() && num[i] == num[i + 1]) i++;
    }
    return ;
}

vector<int> v;
void print() {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int n[10] = {1, 1, 1, 1, 1 ,1};
int main() {

    for (int i = 0; i < 6; i++) {
        v.push_back(n[i]);
    }
    print();
    threesum(v);
        
    return 0;
}

