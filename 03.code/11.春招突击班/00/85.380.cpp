#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        return a > b;
    }
    return a.size() > b.size();
}

int main() {
    map<string, int> ma;
    string ans[105];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ans[i];
        ma[ans[i]] = i + 1;
    }

    sort(ans, ans + n, cmp);
    cout << ma[ans[0]] << endl;
    cout << ans[0] << endl;

    return 0;
}

