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
    cout << str << endl;
    string s;
    for (int i = 0; i < 4; i++) {
        s += str[i];
    }
    cout << (int)s;
    return 0;
}

