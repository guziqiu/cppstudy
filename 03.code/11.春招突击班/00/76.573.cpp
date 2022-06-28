#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct node {
    int raw, now, num;
    bool operator<(const node &b)  const {
        if (now == b.now) return num > b.num;
        return now > b.now;
    }
};

int main() {
    priority_queue<node> que;

    string temp;
    while (cin >> temp) {
        if (temp == "#") break;
        int num, raw;
        cin >> num >> raw;
        que.push({raw, raw, num});
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        node t = que.top();
        que.pop();
        cout << t.num << endl;
        t.now += t.raw;
        que.push(t);
        
    }


    return 0;
}

