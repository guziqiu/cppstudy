#include <iostream>
using namespace std;
#define MAX_N 10000
int arr[MAX_N] = {0};
int f(int n) {
    if (n <= 2) return 0;
    if (n == 3) return 1;
    arr[2] = 1;
    for (int i = 3; i < n; i++) {
        arr[i] = (i - 1) * (arr[i - 1] + arr[i - 2]);
        // cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    return arr[n -1] * n;
}
int main () {
    int n;
    cin >> n;
    cout << f(n) << endl;
    
    
    return 0;
}
