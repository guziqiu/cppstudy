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
    int n, k;
    vector<int> num;

    cin >> n >> k;
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        num.push_back(temp);
    }

    sort(num.begin(), num.end());
    auto it = unique(num.begin(), num.end());
    num.erase(it, num.end());

    if (k <= num.size()) {
        cout << num[k - 1] << endl;
    } else {
        cout << "NO RESULT" << endl;
    }
    // cout << "===" << endl;
    // for (int i = 1, sum = 0; i < n; i++) {
    //     cout << i << " : " << num[i] << endl;
    //     if (num[i] != num[i - 1]) sum++;
    //     if (sum != k) continue;
    //     cout << num[i] << endl;
    //     return 0;
    // }
    // cout << "NO RESULT" << endl;



    return 0;
}
