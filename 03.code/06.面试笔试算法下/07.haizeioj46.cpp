#include <iostream>
#define MAX_N 500000

using namespace std;
int dp[MAX_N + 5];//dp[i] 代表取字符串的前i位，最少分成多少段回文串

bool is_palindrome(string &s, int i, int j) {//判断i~j是否是回文字符串
    while(i < j) {
        if (s[i] - s[j]) return false;//s[i] != s[j]
        i++,j--;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    dp[0] = 0;
    for (int i = 1; i <= s.size(); i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < i; j++) {
            if (is_palindrome(s, j, i - 1))//是回文串
                dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    cout << dp[s.size()] - 1 << endl;



    return 0;
}

