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
    set<int> s;
    s.insert(5);
    s.insert(6);
    s.insert(0);
    s.insert(-2);


    if (s.count(6)) cout << "6 YES" << endl;
    else cout << "6 NO" << endl;


    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
 


    return 0;
}

