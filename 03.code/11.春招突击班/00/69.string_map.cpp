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

struct node {
    string str;
    int num;
};

bool cmp(const node &a, const node &b) {
    if (a.num == b.num) {
        return a.str < b.str;
    }
    return a.num < b.num;
}

node x[105];
int cnt;


int main() {
    int n;
    map<string, int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        m[t]++;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        //cout << it->first << " " << it->second << endl;
        x[cnt].str = it->first;
        x[cnt].num = it->second;
        cnt++;
    }
    sort(x, x + cnt, cmp);
    for (int i = 0; i < cnt; i++) {
        cout << x[i].str << " " << x[i].num << endl;
    }
    return 0;
}

