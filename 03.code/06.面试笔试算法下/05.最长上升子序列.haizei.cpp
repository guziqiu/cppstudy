#include <iostream>

#define MAX_N 1000000
using namespace std;

int arr[MAX_N + 5];
int dp[MAX_N + 5];


int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int ans = 0;//记录最长长度
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] >= arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
            cout << arr[j] << " ";
        }
        cout << endl;
        ans = max(ans, dp[i]);
        cout << "ans = " << ans << endl;
    }

    cout << ans << endl;

    return 0;
}

