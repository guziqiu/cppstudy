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

 
int main() {
    
    int n;
    cin >> n;
    vector<int> h;
    int arr[2][n + 5];

    for (int i = 1, num; i <= n; i++) {
        cin >> num;
        h.push_back(num);
        arr[0][i] = i;
        arr[1][i] = num;
    }
    sort(h.begin(), h.end());

    for (int i = 0; i < n; i++) {
        // cout << 
        for (int j = 1; j <= n; j++) {
            if (h[i] != arr[1][j] || arr[1][j] == 0) continue;
            arr[1][j] = 0;
            i && cout << " ";
            cout << j;
            break;
        }
       
    }
    cout << endl;

      

    return 0;
}
