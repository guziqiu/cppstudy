#include <iostream>
#include <string>
#include <map>
using namespace std;
#define MAX_N 1000
int main () {
    int n, m;
    map<string, int> ma;
    string ans[MAX_N + 5][MAX_N * 5 + 5];
    
    int ind1 = 0;
    int ind2 = 0;
    for (int i = 0; i < m; i++) {
        string name, str;
        cin >> str;
        cin >> name;
        if (ma[str] == 0) {
            ans[ind1++][0] = str;
            ma[str]++;
        }
        ans[ind1][ind2] = name;
        
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < ans[i][j].size(); j++) {
            j && cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
