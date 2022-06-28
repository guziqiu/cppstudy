#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000
struct node {
    long long val, ind;
};

node wt[MAX_N + 5];

bool cmp(node a, node b) {
    return a.val < b.val;
}

long long binary_search(long long n,long long t) {
    long long l = 1, r = n - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (wt[mid].val == t) return wt[mid].ind;
        if (wt[mid].val > t) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}

int main() {
    long long m, n;
    scanf("%lld%lld", &m, &n);

    for (long long i = 1; i <= m; i++) {
        scanf("%lld", &wt[i].val);
        wt[i].ind = i;
    }
    sort(wt, wt + m, cmp);
    for (long long i = 0, t; i < n; i++) {
        scanf("%lld", &t);
        printf("%lld\n", binary_search(m, t));
    }
    return 0;
}

