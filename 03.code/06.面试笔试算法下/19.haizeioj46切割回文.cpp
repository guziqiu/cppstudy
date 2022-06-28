#include <iostream>
#include <vector>
#include <cstring>
#define MAX_N 500000

using namespace std;
int dp[MAX_N + 5];//dp[i] 代表取字符串的前i位，最少分成多少段回文串
vector<int> mark[MAX_N + 5];

int expand(string &s, int i, int j) {
    while (s[i] == s[j]) {
        mark[j + 1].push_back(i + 1);
        --i, ++j;
        if (i < 0 || j >= s.size()) break;
    }
    return 1;
}


int main() {
    string s;
    cin >> s;//一个长度为n(1≤𝑛≤500000)的字符串S，只包含小写字母。
    dp[0] = 0;
    for (int i = 0; s[i]; i++) {
        expand(s, i, i);
        i + 1 < s.size() && expand(s, i, i + 1);
    
    }
    for (int i = 1; i <= s.size(); i++) {
        dp[i] = i;
        for (int j = 0; j < mark[i].size(); j++) {
            dp[i] = min(dp[i], dp[mark[i][j] - 1] + 1);
        }
    }
    cout << dp[s.size()] - 1 << endl;



    return 0;
}

