#include <iostream>
using namespace std;
#define MAX_N 1000
int inv[7] = {0};
//求1~7的逆元

int main() {
    inv[1] = 1;
    for (int i = 2; i < 7; i++) {
        //inv[i] = (-(7/i) * inv[7 % i]);==>变成正数
        inv[i] = ((-(7/i) * (7 % i)) % 7 + 7) % 7;
        cout << i << ":" << inv[i] << endl;
    }

    return 0;
}

