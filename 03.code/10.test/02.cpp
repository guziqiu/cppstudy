#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_N 500000

int dp[MAX_N + 5];

vector<int> arr[MAX_N + 5];
int solve(string &str, int i, int j) {
    while (str[i] == str[j]) {
        arr[j + 1].push_back(i + 1);
        --i, ++j;
        if (i < 0 || j >= str.size()) break;
    }
    return 1;
}

int main() {
    string str;
    dp[0] = 0;
    cin >>  str;
    for (int i = 0; str[i]; i++) {
        solve(str, i, i);
        if (i + 1 < str.size()) solve(str, i, i + 1);
    }
    for (int i = 1; i <= str.size(); i++) {
        dp[i] = i;
        for (int j = 0; j < arr[i].size(); j++) {
            dp[i] = min(dp[i], dp[arr[i][j] - 1] + 1);
        }
    }
    printf("%d\n", dp[str.size()] - 1);

    return 0;
}

