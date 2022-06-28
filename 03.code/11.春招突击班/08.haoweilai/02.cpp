#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000
int arr[MAX_N + 5];


int main() {
    int i;

    while (cin >> arr[i++]);
    sort(arr, arr + i - 1);
    for (int j = 0; j < i; j++) {
        if (arr[j] == arr[j + 1]) cout << arr[j] << endl;
    }

    return 0;
}

