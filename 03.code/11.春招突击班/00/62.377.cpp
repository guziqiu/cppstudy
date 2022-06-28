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
    stack<string> str;
    string temp;
    int ans = 0;
    cin >> temp;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == '(') str.push(")"), ans++;
        if (temp[i] != ')') continue;
        if (!str.empty()) str.pop();
        if (--ans < 0) {
            cout << "NO"  << endl;
            return 0;
        }
    }
    if (ans == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}

