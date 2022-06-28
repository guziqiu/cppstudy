#include <iostream>
#include <algorithm>
using namespace std;
int leapyear(int year){
    if(year%4 == 0 && year%100!=0 || year%400 == 0)
        return 1;
    else
        return 0;
}

int main() {
    int year, month, day, t, y;
    int sum;
    cin >> t;
    while (t--) {
        cin >> year >> month >> day;
        if (month == 2 && day == 29) {
            cout << "-1" << endl;
        } else {
            sum = 0;
            if (month >= 3) {
                for (y = year + 1; y<= year + 18; y++) {
                    if (leapyear(y)) sum += 366;
                    else sum += 365;
                }
            } else if (month <= 2) {
                for (int y = year; y <= year + 17; y++) {
                    if (leapyear(y)) sum += 366;
                    else sum += 365;
                }
            }
            cout << sum << endl;
        }
    }



    return 0;
}

