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

#define mod 100000

int main() {
    int n;
    cin >> n;
    long long arr[n + 5], k, s;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        // arr[i] %= arr[i];
    }
    cin >> k >> s;

    for (int i = 1; i <= n; i++) {
        if (arr[i] % mod != ((k % mod) + (s % mod)) % mod) continue; 
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;

    return 0;
}
