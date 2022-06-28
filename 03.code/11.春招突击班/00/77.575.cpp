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
    cin >> n;
    map<string, int> m;

    for (int i = 0; i < n; i++) {
        string str;
        int temp;
        cin >> str >> temp;
        m[str] = temp;
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        cout << m[str] << endl;
    }


    
    return 0;
}

