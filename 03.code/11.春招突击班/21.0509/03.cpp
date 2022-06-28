#include <iostream>
#include <vector>
using namespace std;
int func(int x, int a, int b, int n) {
    if (x - a < 0) x = 0;
    if (n == 0) return 0;
    return max(x + func(x - a, a, b, n - 1), func(x + b, a, b, n - 1));
}



int main() {
    int t;
    cin >> t;
    int x, a, b, n;

    for (int i = 0; i < t; i++) {
        cin >> x >> a >> b >> n;
        cout << func(x, a, b, n) << endl;
    }

    



    return 0;
}

