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

#define MAX_N 1000000

int num1[MAX_N + 5], num2[MAX_N + 5];


int main() {

    int n, m;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> num1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> num2[i];
    }

    sort(num2, num2 + n);

    long long sum = 0, flag = 0;
    // 二分查找
    for (int i = 0; i < m; i++) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (num2[mid] == num1[i]) {
                if (flag == 1) cout << " ";
                flag = 1;
                sum += num2[mid];
                cout << num2[mid];
                break;
            }
            if (num2[mid] < num1[i]) l = mid + 1;
            else r = mid - 1;
        }
    }

    cout << endl << sum << endl;

    return 0;
}

