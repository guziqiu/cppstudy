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
    stack<char> ans;

    cin >> str;

    int num = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') ans.push(')'), num++;
        else if (str[i] == '{') ans.push('}'), num++;
        else if (str[i] == '[') ans.push(']'), num++;

        if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (str.empty()) {
                cout << "NO" << endl;
                return 0;
            }
            if (str[i] == ans.top()) {
                num--;
                ans.pop();
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (num == 0) cout << "YES" << endl;
    else cout << "NO" << endl;



    return 0;
}

