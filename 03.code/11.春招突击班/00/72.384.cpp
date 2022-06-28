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

int func(int x) {
    if (x % 7 == 0) return 1;
    int t;
    while (x) {
        t = x % 10;
        if (t == 7) return 1;
        x /= 10;
    }
    return 0;
}

int main() {
    int n, x, t;

    int sum;
    cin >> n >> x >> t;

    queue<int> que;

    for (int i = 0; i < n; i++) {
        que.push(i + 1);
    }
    for (int i = 1; i < x; i++) {
        que.push(que.front());
        que.pop();
    }

    sum = n;
    while (sum > 1) {
        if (func(t++)) que.pop(), sum--;
        else que.push(que.front()), que.pop();
    }
    cout << que.front() << endl;



    return 0;
}

