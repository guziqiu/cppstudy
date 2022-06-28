#include <iostream>
using namespace std;

//int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int func(int year, int target) {
    int ans = 0;
    if (target >= 31) return 0;
    if (target <= 27) return 12;
    if (target == 28) {
        if( (year % 4 == 0 && year % 100 != 0 )|| year % 400 ) return 12;
        else return 11;
    }
    if (target == 29) return 11;
    
    if (target == 30) return 7;
    
    //for (int i = 1; i <= 12; i++) {
   //     if (arr[i] > target)  ans++;
    //}
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int year, target;
        cin >> year >> target;
        cout << func(year, target) << endl;
    }
    
    return 0;
}



