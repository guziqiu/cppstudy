 #include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;
 
string replaceSpace(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (strcmp(s[i], " ")) continue;
            strcpy(s[i], "%20");
        }
        return s;
}
    
int main() {
    vector<int> v;
    v.push_back(1);
    cout << v[0] << " " << v.size() << endl;
    return 0;
    cout << max(1, 2) << endl;


    return 0;
}