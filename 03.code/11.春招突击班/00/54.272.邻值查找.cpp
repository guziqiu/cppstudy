#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

#define MAX_N 100000

int arr[MAX_N + 5] = {0};
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        
    }
    for (int i = 1; i < n; i++) {
        int ans = INT_MAX, ind;
        for (int j = 0, temp; j < i; j++) {
            temp = fabs(arr[i] - arr[j]);
            if (ans >= temp) ans = temp, ind = j;    
        }
        //printf("arr[%d] = %d, arr[%d] = %d\n", i + 1, arr[i], ind + 1, arr[ind]);
        cout << ans << " " << ind + 1 << endl;
    }



    return 0;
}

