#include <iostream>
using namespace std;
#define MAX_N 1000000
long long arr[MAX_N + 5][MAX_N + 5] = {0};

long long func(int n, int max) {
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || i == 1) arr[i][j] = 1; 
            else {
                if (j == i) arr[i][j] = arr[i][j - 1] + 1;
                else if ((i - j) < j) arr[i][j] = arr[i - j][i - j] + arr[i][j - 1];
                else arr[i][j] = arr[i - j][j] + arr[i][j - 1];
            }
        }
    }
    return arr[n][max];
    

/*
    if (n == 1 || max == 1) return 1;
    if (n < max) {
        return func(n, max);
    }
    if (n == max) {
        return 1 + func(n, n -1);
    } else {
        return func(n - max, max) + func(n, max - 1);
    }
    */ 
}


int main() {
    int n;
    cin >> n;
    cout << func(n, n) << endl; 
    return 0;
}

