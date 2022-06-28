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

int main() {
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0, temp; i < n; i++) {
        //temp = rand() % 1000;
        //cout << temp << endl;
        cin >> temp;
        arr.push_back(temp);
        
    }
    // 去重
    sort(arr.begin(), arr.end());
    auto it = unique(arr.begin(), arr.end());
    arr.erase(it, arr.end());

    cout << arr.size() << endl;
    int i = 0;
    for (auto it : arr) {
        i++ && cout << " ";
        cout << it;
    }
    cout << endl;

    return 0;
}
