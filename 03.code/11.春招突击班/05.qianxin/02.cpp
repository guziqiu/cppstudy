#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000
char car[MAX_N + 5];
int funcn(int n) {// 计算阶乘
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}
int func(int n) {
    int ans = 3;
    for (int i = 4; i <= n; i++) {
        ans  = ans * (i - 2) + funcn(i - 1);
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> car[i];
    }

    for (int i = 0; i  < n; i++) {
        for (int j = 0; j < n; j++) {
            j && cout << "-";
            cout << car[j];
        }
        cout << " ";
    }


    //sort(car, n);
    cout << func(n) << endl;
    
    
    return 0;
}
