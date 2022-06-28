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

int main() {
    string s1, s2;
    int n;
    cin >> s1 >> n >> s2;
    if (s1.size() < 100) cout << s1.size() << endl;
    else cout << 100 << endl;
    s1.insert(n - 1, s2);
    cout << s1 << endl;
    cout << s1.size() - s1.rfind("x") << endl;
    return 0;
}

