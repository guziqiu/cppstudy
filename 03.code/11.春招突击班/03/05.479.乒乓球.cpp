#include <iostream>
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

char str[30];
int ans1[10005][2], ans2[10005][2], ind1, ind2;

int main() {

    while (cin >> str) {
        for (int i = 0; str[i]; i++) {
            if (str[i] == 'E') {
                for (int i = 0; i <= ind1; i++) {
                    cout << ans1[i][0] << ":" << ans1[i][1] << endl;
                }
                cout << endl;
                for (int i = 0; i <= ind2; i++) {
                    cout << ans2[i][0] << ":" << ans2[i][1] << endl;
                }

                return 0;
            }
            else if (str[i] == 'W') {
                ans1[ind1][0]++;
                ans2[ind2][0]++;
            } else {
                ans1[ind1][1]++;
                ans2[ind2][1]++;
            }
            if ((ans1[ind1][0] >= 11 || ans1[ind1][1] >= 11) && 
                (ans1[ind1][0] - ans1[ind1][1] >= 2 || 
                ans1[ind1][1] - ans1[ind1][0] >= 2)) ind1++;
            if ((ans2[ind2][0] >= 21 || ans2[ind2][1] >= 21) && 
                (ans2[ind2][0] - ans2[ind2][1] >= 2 || 
                ans2[ind2][1] - ans2[ind2][0] >= 2)) ind2++;
 
        }
    }
    
    return 0;
}

