#include <iostream>
using namespace std;

int func(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int flow = 0;
    int fast = 1;
    while (fast <= n) {
        if (arr[flow] != arr[fast]) {
            fast++;
            flow++;
        }
        fast++;
        if (arr[flow + 1] != arr[fast]) {
            arr[flow + 1] = arr[fast];
        } 
    }
    for (int i = 0; i < flow; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return flow;
}


int arr[] = {1, 1, 1, 2, 2, 3, 3, 4, 4, 4};

int main() {

    cout << func(arr, 10) << endl;

    return 0;
}

