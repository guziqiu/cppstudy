#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') 
        for (int j = i + 1; j < str.size(); j++) {
            if (str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U') {
                int t = j - i;
                //cout << str[i] << str[j] << endl;
                ans = max(ans, t);
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

