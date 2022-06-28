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
    cin >> n;
    int ans = 0;
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        ans = max(ans, temp);
    }
    cout << ans << endl;

    return 0;
}
