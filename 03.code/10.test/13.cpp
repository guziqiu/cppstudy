#include <iostream>
using namespace std;
#define MAX_N 1000
int stack[MAX_N + 5], top;
int height[MAX_N + 5][MAX_N + 5];
int arr[MAX_N + 5];

int main() {
    int m, n;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &height[i][j]);
            if (height[i][j] == 1) height[i][j] += height[i - 1][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        top = -1;
        stack[++top] = 0;
        height[i][0] = -1;
        arr[0] = 0;
        for (int j = 1; j <= m; j++) {
            while (top != -1 && height[i][stack[top]] > height[i][j]) --top;
            arr[j] = height[i][j] * (j - stack[top]) + arr[stack[top]];
            stack[++top] = j;
            arr[j] %= 10007;
            ans += arr[j];
            ans %= 10007;
        }

    }
    printf("%d\n", ans);
    
    return 0;
}

