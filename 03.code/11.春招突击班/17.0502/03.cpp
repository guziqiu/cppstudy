#include <iostream>
using namespace std;

int main() {
    int k = 10;
    int num = 0;
    int x;
    cout << ((x = 4 * 5, x * 5), x + 25) << endl;
    while (k = 1) {
        cout << "k :" << k << endl;
        k = k - 1;
        num++;
        if (num >= 10) break;
    }
    return 0;
}

