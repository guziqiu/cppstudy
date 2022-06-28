#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define mod 1000000007

long long arr[100000 + 5];
int main() {
    int n;
    // cin >> n;
    n = 88818; //465277080
    //n = 37043; 300410965
    //n = 4;
    
    //arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;// 2 3
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] % mod + arr[i - 2] % mod;
        arr[i] %= mod;
    }
    cout << (arr[n] % mod) << endl;
    // cout << mod;

    return 0;
}
