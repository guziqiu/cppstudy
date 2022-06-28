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

#define MAX_N 1000000

int prime[MAX_N + 5] = {0};


void init() {
    prime[1] = 1;
    for (int i = 2; i <= MAX_N / 2 + 1; i++) {
        if (prime[i]) continue;
        for (int j = 2 * i; j <= MAX_N; j += i) prime[j] = 1;
    }
    return ;
}

int main() {
    init();
    int n, m;
    cin >> n >> m;
    
    for (int i = m; i <= n; i++) {
        //cout << i << ", " << prime[i] << endl;
        if (prime[i]) continue;
        cout << i << endl;
    }

    return 0;
}
