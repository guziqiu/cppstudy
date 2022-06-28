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
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> m;
    m[55] = 6;
    m[66] = 7;
    m[22] = 8;
    m[1] = 2;

    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }




    return 0;
}

