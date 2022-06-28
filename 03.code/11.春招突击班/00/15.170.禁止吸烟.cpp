#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    //cin >> n;
    n = 1;
    string s[n];
    //stating a kind of array//
    for(int i = 0;i < n; i++){
        //cin >> s[i];
        s[i] = "KBan_smokingTWDBan_smokingQCgXcupA";
		for (int j = 0; j + 11 < s[i].size(); j++) {
        if(s[i].find("Ban_smoking") != string::npos){
            s[i].replace(s[i].find("Ban_smoking"),11 ,"No_smoking");
            // replacing the eleventh space//
        }
		}
		cout << "KBan_smokingTWDBan_smokingQCgXcupA" << endl;
        cout << s[i] << endl;
    //program output//
    }
    return 0;
}