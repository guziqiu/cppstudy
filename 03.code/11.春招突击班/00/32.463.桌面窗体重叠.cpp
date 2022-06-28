#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int a1, a2, b1, b2;
    int c1, c2, d1, d2;
    cin >> a1 >> a2 >> b1 >> b2;
    cin >> c1 >> c2 >> d1 >> d2;
    //   b1
    // a1 a2
    //   b2

    //   d1
    // c1 c2
    //   d2

    
    // 0
    int sum = 0;
    if ((c2 <= a1) || (d1 >= b2) || (c1 >= a2) || (d2 <= b1)) sum = 0;
    int a, b;

    // (a1, b1)(a2, b1)
    // (a1, b2)(a2, b2)
    
    // (c1, d1)(c2, d1)
    // (c1, d2)(c2, d2)

    if (a1 < c1 && c1 < a2) { // 
        if (a1 < c2 && c2 < a2) a = c2 - c1;
        a = a2 - c1;
    } else if (a1 < c2 && c2 < a2) {
        if (c1 < a1) a =  

    }





    if (c2 > a1) 
    sum = fabs();



    cout << sum << endl;

    return 0;
}
