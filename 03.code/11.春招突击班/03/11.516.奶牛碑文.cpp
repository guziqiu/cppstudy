#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
long long n, numc[100005], numw[100005];
string str;

int main() {
    string str;
    int n;
    cin >> n;
    cin >> str;

    int cn = 0, wn = 0;
    for (int i = 0, j = str.size() - 1; i < str.size(); i++, j--) {
        if (str[i] == 'C') cn++;
        if (str[j] == 'W') wn++;
        numc[i] = cn;
        numw[j] = wn;
    }
    long long ans = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'O') {
            ans += numc[i] * numw[i];
            cout << ans << endl;
        }
    }

    cout << ans << endl;



    return 0;
}

