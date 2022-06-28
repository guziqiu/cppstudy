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

#define MAX_N 10000000 

int arr[MAX_N + 5]; 

void solve(int *num, int n, int t) {
    int left = 0, right = n - 1, mid;
    while (left < right) {
        if (num[left] + num[right] == t) {
            cout << left << " " << right << endl;
            left++, right--;
        }
        if (num[left] + num[right] > t) right--;
        if (num[left] + num[right] < t) left++;
    }
    return ;
}

int main() {
    int n, t;

    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    solve(arr, n, t);


    return 0;
}

