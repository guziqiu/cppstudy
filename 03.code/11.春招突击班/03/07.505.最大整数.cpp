#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000

string arr[MAX_N + 5];

bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, cmp);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    
    cout << endl;

    
    return 0;
}

