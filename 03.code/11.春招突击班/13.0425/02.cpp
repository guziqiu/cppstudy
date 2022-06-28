#include <iostream>
#include <vector>
#include <string>
using namespace std;
int judge(string s, int l, int r) {
    cout << s.substr(l, r) << endl;
    while (l < r) {
        if (s[l] != s[r]) return 0;
        l++;
        r--;
    }
    return 1;
}
string longestPalindrom(string s) {
    string ret;
    int len = s.size();
    if (len < 2) return ret;
    int maxl = 1;
    ret = s.substr(0, 1);
    // cout << ret << endl;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (j - i + 1 > maxl && judge(s, i, j)) {
                maxl = j - i + 1;
                ret = s.substr(i, j - 1);
       //         cout << ret << endl;
            }
        }
    }
    return ret;
}
int main() {
    string str = "abcddcef";
    cout << longestPalindrom(str) << endl; 
    return 0;
}

