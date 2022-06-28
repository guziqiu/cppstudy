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

int n, cnt[25];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cnt[t]++;
    }
    for (int i = 0; i <= 20; i++) {
        for (int j = 1; j <= cnt[i]; j++) {
            cout << i << " ";
        }
    }


    return 0;
}
