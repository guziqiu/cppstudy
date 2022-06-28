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
    
    set<int> s;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        s.insert(t);
    }

    cout << s.size() << endl;

    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;



    return 0;
}

