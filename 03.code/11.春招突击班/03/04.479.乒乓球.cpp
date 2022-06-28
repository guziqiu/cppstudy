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

void score11(int x, int y) {
    int a = x, b = y;
    while (x >= 11 || y >= 11) {
        a = x % 11;
        b = y % 11;
        cout << a << ":" << b << endl;
        x -= 11;
        y -= 11;
    }
    cout << a << ":" << b << endl;
    return ;
}

void score21(int x, int y) {

}

int main() {
    
    string str[3000];
    
    int n;
    for (int i = 0; ; i++) {
        cin >> str[i];
        n = i;
        if (str[i][str[i].size() - 1] == 'E') break;
    }
    int a[3000] = {0}, b[3000] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < str[i].size(); j++) {
            if (str[i][j] == 'W') a[i]++;
            else if (str[i][j] == 'L') b[i]++;
            else break;
        }
    }
    score11(a, b);
    score21(a, b);

    return 0;
}

