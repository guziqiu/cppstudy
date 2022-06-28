#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
    
map<string, int> name;
vector<string> str[1005]; // 用户浏览东西


int main() {
    int n, m, total = 0;
    cin >> n >> m;

    
    for (int i = 0; i < m; i++) {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        if (name[temp1] == 0) {
            total++;
            name[temp1] = total;
            str[total].push_back(temp1);
        }
        int ind = name[temp1];
        str[ind].push_back(temp2);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < str[i].size(); j++) {
            j && cout << " ";
            cout << str[i][j];
        }
        cout << endl;
    }






    return 0;
}

