#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int arr[27];
int main() {
    for (int i = 0; i < 26; i++) {
        cin >> arr[i];
    }
    
    map<char, int> m;
    string s, t;
    cin >> s;
    cin >> t;
    
    for (int i = 0; i < s.size(); i++) {
        m[s[i]] = 1;
    }
    string str;
    for (int i = 0; i < t.size(); i++) {
        if (m[t[i]] == 1) str += t[i];
    }
    cout << str << endl;
    string ans;
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        //cout << "i = " << str[i] - 'a' - 0 << endl;
        if (arr[str[i] - 'a' - 0] < 0) continue;
        ans += str[i];
        sum += arr[str[i] - 'a' - 0];
    }
    cout << sum * 2 << endl;

        
    return 0;
}

