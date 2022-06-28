#include <iostream>
#include <cstdio>
#include <algorithm>
using std::sort;
#define MAX_N 100000
struct node {
    int val, ind;
};

bool cmp(node a, node b) {
    return a.val < b.val;
}
node w[MAX_N + 5];
int main() {
    int m, n;
    scanf("%d%d", &m, &n);

    for (int i = 0; i < m; i++) {
        scanf("%d", &w[i].val);
        w[i].ind = i + 1;
    }

    sort(w, w + m, cmp);
    for (int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        if (t > w[m - 1].val) {
            printf("0\n");
            continue;
        }
        int l = 0, r = m, mid;
        int flag = 1;
        while (l != r) {
            mid = (l + r) >> 1;
            if (w[mid].val >= t) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", w[r].ind);
    }

    
    return 0;
}

