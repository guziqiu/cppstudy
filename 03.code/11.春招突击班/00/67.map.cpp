#include <iostream>
#include <cmath>
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

struct node {
    int num, cnt;
    bool operator<(const node &b) const { // 默认重载小于号
        return this->num < b.num;
    }
};


int main() {
    map<node, int> m;
    node t = (node){5, 6};
    m[t] = 4;
    t.num = 99;
    m[t] = 7;
    t.num = 88;
    m[t] = 77;
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first.num << " " << it->second << endl;
    }







/*
    
    map<string, int> m;
    m["abc"] = 123;
    m["xyz"] = 12;
    m["asd"] = 45;
    cout << m.size() << endl;

    for (auto it = m.begin(); it != m.end(); it++) { // 通过迭代器访问map
        cout << it->first << " " << it->second << endl;
    }
    */

    return 0;
}
