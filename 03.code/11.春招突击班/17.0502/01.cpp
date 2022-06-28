#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100

int cmp(int a, int b) {
    return a > b;
}
int func(int *arr, int n) {
    int ret = 0;
    sort(arr, arr + n, cmp);
    vector<int> a, b;
    a.push_back(arr[0]);
    b.push_back(arr[0]);
    for (int i = 1; i < n - 1; i++) {
        if (i % 2 == 0) a.push_back(arr[i]);
        else b.push_back(arr[i]);
    }
    a.push_back(arr[n - 1]);
    b.push_back(arr[n - 1]);
    for (int i = 1; i < a.size(); i++) {
        ret = max(ret, a[i - 1] - a[i]);
    }
    cout << endl;
    for (int i = 1; i < b.size(); i++) {
        ret = max(ret, b[i] - b[i - 1]);
    }

    return ret;
}


int main() {
    int n;
    // cin >> n;
    n = 4;
    int arr[MAX_N + 5] = {100, 150, 200, 250};
    for (int i = 0; i < n; i++) {
        //cin >> arr[i];
    }
    cout << func(arr, n) << endl;

    return 0;
}

