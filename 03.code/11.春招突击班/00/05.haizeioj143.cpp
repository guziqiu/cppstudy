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
#include <cmath>
using namespace std;

int solve(int a, int b) {
    int ans = a * 10 + b;
    for (int i = 2; i < ans; i++) {
        if (ans % i == 0) return 0;
    }
    return 1;
}

int mysqrt(int a, int b) {
    int ans = a * 10 + b;
    int temp = sqrt(ans);
    if (pow(temp, 2) == ans) return 1;
    return 0;
}

int main() {
    int a, b;
    cin >> a >> b;
    int sum = 0;
    for (int i = a, A, B, C, D; i <= b; i++) {

        if (i % 6 != 0) continue;
        A = (i / 1000) % 10; //千位数字与百位数字构成的两位数 𝐴𝐵 是一个质数
        B = (i / 100) % 10;
        if (!solve(A, B)) continue;
        C = (i / 10) % 10;//.十位数字与个位数字构成的两位数 𝐶𝐷 是一个完全平方数。
        D = i % 10;
        if (!(mysqrt(C, D))) continue;
        
        //cout << A << B << endl;
        //cout << C << D << endl;
        
        sum++;
        sum != 1 && printf(" ");
        cout << i;
    }
    cout << endl;
    cout << sum << endl;
    return 0;
}

