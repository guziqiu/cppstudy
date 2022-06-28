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
#define MAX_N 400000

long long num1[MAX_N + 5], num2[MAX_N + 5], ans[MAX_N + 5];


int main() {
    priority_queue<int> que;
    long long n;
    scanf("%d", &n);

    for (long long i = 0; i < n; i++) {
        scanf("%d", num1 + i);
    }
    for (long long i = 0; i < n; i++) {
        scanf("%d", num2 + i);
        que.push(num1[0] + num2[i]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = num1[i] + num2[j];
            if (sum < que.top()) {
                que.pop();
                que.push(sum);
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < n;i++) {
        ans[i] = que.top();
        que.pop();
    }

    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", ans[i]);
    }


        
    return 0;
}

