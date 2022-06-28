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
    priority_queue<int, vector<int>, greater<int> > q;
    int n;
    cin >> n;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a;
        if (a == 1) {
            scanf("%d", &b);
            q.push(b);
        } else if (a == 2) {
            if (q.empty()) printf("empty\n");
            else printf("%d\n", q.top());
        }
        else {
            if (!q.empty()) q.pop();
        }

    }


    return 0;
}

