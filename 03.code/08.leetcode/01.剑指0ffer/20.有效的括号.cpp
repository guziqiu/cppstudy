#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<algorithm>
using namespace std;

bool isValid(string s) {
    stack<char> res;
    if (s.size() % 2) return false;//字符串为奇数个
    for (int i = 0; i < s.size(); i++) {
         switch (s[i]) {
             case '(' :
             case '[' :
             case '{' :
                res.push(s[i]);
                //cout << res.top() << " " ;
                break;
             case ')' :
                if (res.empty()) return false;
                if (res.top() == '(') res.pop();
                else  return false;
                break;
             case ']' :
                if (res.empty()) return false;
                if (res.top() != '[') return false;
                if (res.top() == '[') res.pop();   
                break;
             case '}' :
                if (res.empty()) return false;
                if (res.top() != '{') return false;
                if (res.top() == '{') res.pop();
                break;
         }
    }
    return res.empty();
}
bool isValid1(string s) {
    stack<char> str;
    for (char c : s) {
        if (!str.empty()) {
             if ((str.top() == '(' && c == ')') || (str.top() == '[' && c == ']') 
             || (str.top() == '{' && c == '}')) {
                    str.pop();
                    continue;
             }
        }
        str.push(c);
    }
    return str.empty();

}
bool isValid2(string s) {
    if (s.size() % 2) return false;
    stack<char> str;
    for (char c : s) {
        if (c == '{') str.push('}');
        else if (c == '(') str.push(')');
        else if (c == '[') str.push(']');
        else if (str.empty() || str.top() != c ) return false;
        else if (str.top() == c ) str.pop();
    }
    return str.empty();

}

int main() {
    cout << isValid2("(") << endl; 
    cout << isValid2("()") << endl;
    cout << isValid2("()[]{}") << endl;
    cout << isValid2("([)]") << endl;
    cout << isValid2("{[]}") << endl;


    return 0;
}