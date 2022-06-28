#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int n;
    cin >> str >> n;

    for (int i = n; i > 0; i--) {
        int ind = str.size() - 1;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] > str[j + 1]) {
                ind = j;
                break;
            }
        }
        str.replace(ind, 1, "");
    }
    int flag = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '0') flag = 1;
        if (flag == 1) cout << str[i];
    }
    cout << endl;

    return 0;
}

