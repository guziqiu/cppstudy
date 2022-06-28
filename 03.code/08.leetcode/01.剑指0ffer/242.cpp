#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
bool isAnagram1(string s, string t) {
    if (s.length() != t.length()) return false;
    
     
    return s == t;
}

int main() {
    

    return 0;
}