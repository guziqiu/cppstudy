#include <iostream>
using namespace std;

int judge(int num, int t) {
    while (num) {
        if (num % 10 == t) return 1;
        num /= 10;
    }
    return 0;
}


int main() {

    int m, t;
    cin >> m >> t;

    int ans = 0;
    for (int i = 0; i <= m; i++) {
        if (judge(i, t)) ans++;
    }
    cout << m - ans << endl;

        
    return 0;
}

