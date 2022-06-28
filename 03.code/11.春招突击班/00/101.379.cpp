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
#define MAX_N 200000
long long arr[MAX_N + 5] = {0};
long long maxarr[MAX_N + 5] = {0};

int main() {
    //queue<int> q;
    long long indarr = 0, indmax = 0;
    long long n;
    scanf("%d", &n);

    for (long long i = 0, t; i < n; i++) {
        scanf("%lld", &t);
        if (t == 0) {
            long long x;
            scanf("%lld", &x);
            arr[++indarr] = x;
            maxarr[++indmax] = max(arr[indarr], maxarr[indmax - 1]);
        } else if (t == 1)  indarr--, indmax--;
        else if (t == 2) {
            printf("%lld\n", maxarr[indmax]);
        }
    }

    // 1 2 
    // 2 2
    // 1 2 4 2
    // 2 1 2 1 1 2 1 2
    // 4   4     1   0

    return 0;
}

