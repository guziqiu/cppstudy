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

int func(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return (func(n - 1) + func(n - 2));
}

int func2(int n) {
    int a = 1, b = 2, c = 3;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    cout << func(44) << endl;
    cout << func2(44) << endl;
    return 0;
}

