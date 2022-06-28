#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
    vector<char> str;
    int ans = 0, sum = 0;
    string a;
    // cin >> a;
    a = "((({}[]((()";
    // cout << a << endl;
    cout << a << " : " << a.size() << endl;

    for (int i = 0; i < a.size(); i++) {
        
        if (a[i] == '[') str.push_back(']');
        else if (a[i] == '{') str.push_back('}');
        else if (a[i] == '(') str.push_back(')');
        cout << i << " : " << a[i] << " : " <<  str.size() << endl;
        
        if (str.size() == 0) continue;
        if (a[i] == str[str.size() - 1]) {
            sum++;
            str.pop_back();
            //ans = max(ans, sum);
            
        } 
        // else {
        //     ans = max(ans, sum);
        //     str.clear();
        // }
    }
    cout << ans * 2 <<  endl;

    return 0;
}
