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

int solve(int n) {
    if (n < 0) return 0;
    int ans = 0;
    int temp = n;
    while(n) {
        ans = n % 10 + ans * 10;
        n /= 10;
    }
   
    return temp == ans;
}

int main() {
    int n;
    int sum = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        solve(i) && sum++;
        // if (solve(i)) sum++;
        // cout << "==> " << solve(i) << endl;
    }
    cout << sum << endl;

    return 0;
}
