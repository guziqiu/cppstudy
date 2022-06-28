#include <iostream>
using namespace std;

int func(long long x) {
    if (x == 1) return 0;
    if (x == 2) return 1;
    while (x > 1) {
        if (x % 2 == 0) {
            x /= 2;
           // cout << x << endl;
            continue;
        }
        //cout << "x % 2 != 0 : " << x << endl;
        return 0;
    }
    return 1;
}


int main() {
    long long x;
    cin >> x;
    cout << (func(x) == 1 ? "True" : "False") << endl;
    
    return 0;
}
