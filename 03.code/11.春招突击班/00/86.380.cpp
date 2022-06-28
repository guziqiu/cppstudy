#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    map<string, int> ma;
    string ans;
    int ansnum;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        if (temp.size() > ans.size()) ans = temp, ansnum = i;
        else if (temp.size() == ans.size() && temp > ans) ans = temp, ansnum = i;
        
    }

    cout << ansnum + 1 << endl;
    cout << ans << endl;

    return 0;
}

