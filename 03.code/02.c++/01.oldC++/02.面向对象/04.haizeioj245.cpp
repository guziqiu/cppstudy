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

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    //sort(arr.begin(), arr.end());
    //nth_element();
    int pos = arr[n / 2];
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += abs(arr[i] - pos);
    }
    cout << sum << endl;


    return 0;
}

