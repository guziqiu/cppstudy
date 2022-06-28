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
using namespace std;

int n, m;
int arr[205][205];
int ans[205][205];
int main() {
    cin >> n >> m;

    // n * m n行m列
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    // m * n m行n列
    for (int i = n - 1, k = 0; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            //printf("ans[%d][%d] = arr[%d][%d] = %d\n", j, i, k, j, arr[k][j]);
            ans[j][i] = arr[k][j];
        }
        k++;
    }
    //cout << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) { 
            j && cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }





    return 0;
}

