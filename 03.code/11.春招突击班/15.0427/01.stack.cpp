#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX_N 1000000
stack<int> s;
int retmax = INT_MIN;
int retmin = INT_MAX;
int pop() {
    int t = s.top();
    s.pop();
    return t;
}
int func(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        s.push(arr[i]);
        retmax = max(arr[i], retmax);
    }
    pop();
    return 1;
}
int max() {
    return retmax;
}
int min() {
    return retmin;
}

int main() {
    int n;
    cin >> n;
    int arr[MAX_N] = {0};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    func(arr, n);
    sort(arr, arr + n - 1);
    cout << arr[n - 2] << "," << arr[0] << endl;

    return 0;
}

