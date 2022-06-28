#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10

int a[MAX_N + 5];


int main() {
    int x, n;
    cin >> n >> x;

    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    double ans = 0.0;
    for (int i = 0; i <= n; i++) {
        ans += a[i] * (pow(x, i));
    }

    cout << ans << endl;



    return 0;
}

