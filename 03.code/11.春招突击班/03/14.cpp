#include<iostream>
#include<cmath>
using namespace std;
#define MAX_N 100000
int arr[MAX_N + 5];
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (i % 2 == 0) ans = max(ans, fabs(arr[i] - arr[i - 1]));
    }
    
    cout << ans << endl;
    
    return 0;
   }
