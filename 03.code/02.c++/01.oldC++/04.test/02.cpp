#include<iostream>
#include <cstdio>
#define MAX_N 500
long long arr[MAX_N + 5];
int main() {
    
    int n;
    n = 500;
    // 1       1
    // 1 + 1   2
    // 2 + 1   3
    // 3 + 2   5
    // f(n) = f(n - 1) + f(n - 2);
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 5;
    int i = 4;
    for (; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
        printf("%lld\n", arr[i - 1]);
    }
    
    
    
    
    
    return 0;
}
