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
    string str;
    cin >> str;
    
    int n;
    cin >> n;
    int total = str.size();
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        if (t == "L") {
            if (total == 0) continue;
            total--;
        } else if (t == "D") {
            if (total == str.size()) continue;
            total++;
        } else if (t == "B") {
            if (total == 0) continue;
            str.erase(total - 1, 1);
            total--;
        } else if (t == "P") {
            string ins;
            cin >> ins;
            str.insert(total, ins);
            total += ins.size();
        }
        cout << str <<  endl;
    }
    cout << str <<  endl;

    return 0;
}

