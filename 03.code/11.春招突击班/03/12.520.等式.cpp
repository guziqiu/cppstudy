#include <iostream>
using namespace std;

long long a, num[15000005];


int main() {
    for (int i = 1; i <= 15000000; i++) {
        num[i] = num[i - 1] + i;
    }

    cin >> a;
    for (int i = a; ; i++) {
        int l = i + 1, r = 15000000;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (num[mid] - num[i] == num[i - 1]) {
                cout << i << " " << mid << endl;
                return 0;
            } 
            if (num[mid] - num[i] > num[i - 1]) r = mid - 1;
            else l = mid + 1;
        }
    }
        
    return 0;
}

