#include <iostream>
#include <stack>
using namespace std;


#define MAX_N 100000
int arr[MAX_N + 5];


int main() {

    int n;
    cin >> n;
    stack<int> s;
    int i = 0;
    while (cin >> arr[i++]);
    for (int j = 0; j < n; j++) {
        s.push(arr[j]);
    }
    //for (int j = 0; j < i; j++) {
    //    cout << "arr[i] = " << j << ":" << arr[j] << endl;
    //}

    for (int j = i; j < n + i; j++) {
        arr[j - 1] = s.top();
        s.pop();
    }

    for (int j = n; j < i + n - 1; j++) {
        cout << arr[j] << " ";
    }
    cout << endl;




    return 0;
}

