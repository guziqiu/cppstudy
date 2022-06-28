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

struct node {
    string name;
    int money;
    //int store;
};


int main() {
    map<string, int> m, s;
    int n, k;
    scanf("%d %d", &n, &k);
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        string str;
        char s1[100000];
        int temp, st;
        scanf("%s %d %d", s1, &temp, &st);
        str = s1;
        //cin >> str >> temp >> st;
        m[str] = temp; // 收益
        s[str] = st;  // 库存
    }

    for (int i = 0; i < k; i++) {
        string str;
        long long num;
        cin >> str >> num;
        if (num <= s[str]) {
            s[str] -= num;
            ans +=  m[str] * num;
        } else {
            //cout << -(i + 1)  << endl;
            printf("-%d\n", i + 1);
        }
    }

        //cout << ans << endl;
        printf("%lld\n", ans);
    
    return 0;
}

