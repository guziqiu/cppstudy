#include <iostream>
using namespace std;
#define MAX_N 100000000
int arr[MAX_N + 5] = {0};
int func(int n) {
    if (n == 0) return 0;
    
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 5;
    for (int i = 4; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
    
}
int main() {
    int n;
    cin >> n;
    cout << func(n) << endl;
    return 0;
}
