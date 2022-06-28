#include<iostream>
#include <cmath>
using namespace std;

long long func(long long base) {
    int year = 1;
    int  i = 1;
    double ans = 0;
    while (year <= 20) {
        ans += base * 12;
        if (year % 2 == 0) {
            base = base * pow((1 + 0.08), i++);
            cout << "year : " << year << ",base : " << base << endl;
        }                
        year++;
    }
    return ans;
}


int main() {
    long long base;
    //cin >> base;
    base = 1000;
    cout << func(base) << endl;
    
    
    return 0;
}
