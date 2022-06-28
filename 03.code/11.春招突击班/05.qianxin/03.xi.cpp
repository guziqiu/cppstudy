#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int arr[10];
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }
    
    for (int i = 9; i > 0; i--) {
        int r = rand() % i;
        printf("arr[%d] = %d, arr[%d] = %d\n", r, arr[r], i, arr[i]);
        int temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
        for (int i = 0; i < 10; i++) cout << arr[i] << " ";
        cout << endl;
    }
    



    return 0;
}

