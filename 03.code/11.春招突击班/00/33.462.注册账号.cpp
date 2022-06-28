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

//#define mod 1000007

int main() {

    string str;

    int n;
    cin >> n;
    string type;
    int64_t  sum = 0, num = 0;
    int woman = 0, man = 0;

    for (int i = 0; i < n; i++) {
        cin >> type;
        cin >> str;
        if (type == "i") {
            int temp = (int)str[str.size() - 2];
            if (temp % 2) man++; 
            else woman++;
        } else {
            sum += atoi(str.c_str());
			//sum %= mod;
            num++;
        }
    }

   cout << man << " " << woman << " " << (sum / num) << endl;






    return 0;
}
