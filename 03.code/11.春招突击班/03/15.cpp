#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

void inttostr(long long m, string str, int n) {
    if(m == 0) {
        str = '0'; 
        return ;
    }
    while (m) {
        cout << m << endl;
        int t = m % n;
        if (t >= 0 && t <= 9) str += atomic_uchar(t);
        else str += t - 10 + 'A';
        m /= n;
    }
    reverse(str.begin(), str.end());
}


int main() {
    long long m;
    int n;
    cin >> m;
    string str;
    inttostr(m, str, n);
    cout << str << endl;
    
    
    return 0;
}
