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

#define MAX_N 1000000

int num1[MAX_N + 5], num2[MAX_N + 5];


int main() {

    int m, n;
    cin >> m >> n;

    map<int, int> t1;
    set<int> t2;

    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        t1[i] = temp;
    }
    for (int j = 0; j < n; j++) {
        int temp;
        cin >> temp;
        t2.insert(temp);
    }

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (t2.count(t1[i]) == 1) cout << t1[i] << " ", sum += t1[i];
    }
    
    cout << endl;
    cout << sum << endl;

    return 0;
}

