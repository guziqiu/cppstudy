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
    vector<int> stu;
    cin >> n;
    for (int i = 1, temp; i <= n; i++) {
        cin >> temp;
        stu.push_back(temp);
    }
    sort(stu.begin(), stu.end());
    for (int i = 0; i < n; i++) {
        i && cout << " ";
        cout << stu[i];
    }
    cout << endl;



    return 0;
}
