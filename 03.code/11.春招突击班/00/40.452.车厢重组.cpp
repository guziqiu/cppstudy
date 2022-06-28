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

#define MAX_N 10000
int arr[MAX_N + 5] = {0};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                sum++;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << endl;
    // }
    cout << sum << endl;


    return 0;
}
