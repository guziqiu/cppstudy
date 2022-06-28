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

int solve(string a, string b) {
    if(a == b) return 1;
    return 0;
}

int main() {

    vector<vector<string>> str;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<string> temp;
        for (int j = 0, a; j < 6; j++) {
            cin >> a;
            string b = to_string(a);
            temp.push_back(b);
        }
        sort(temp.begin(), temp.end());
        str.push_back(temp);
    }
    //if (n == 10) cout << "No two snowflakes are alike." << endl;

    for (int i = 0; i < str.size(); i++) {
        for (int j = i + 1; j < str[i].size(); j++) {
            for (int k = 0; k < 6; k++) { 
                if (str[i][k] == str[j][k]) {
                    cout << str[i][k] << str[j][k] << endl;
                    continue;
                }
                cout << "No two snowflakes are alike." << endl;
                return 0;
            }
            
            cout << "Twin snowflakes found." << endl;
            return 0;
            
        }
    }

        return 0;
}

