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

    int n;
    scanf("%d", &n);

    vector<string> name;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        name.push_back(temp);
    } 
    for (int i = 0; i <  n; i++) {
        if (name[i][0] >= 'a' && name[i][0] <= 'z') name[i][0] -= 32;
        for (int j = 1; j < name[i].size(); j++) {
            if (name[i][j] >= 'A' && name[i][j] <= 'Z') name[i][j] += 32;
        }
    }
    sort(name.begin(), name.end());
    for (int i = 0; i < n; i++) cout << name[i] << endl;

    return 0;
}
