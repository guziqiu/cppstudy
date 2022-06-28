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
#define MAX_N 1000000000

struct node{
    string str;
    int num;
};

char s[MAX_N + 5];
node x[MAX_N + 5];

bool cmp(const node &a, const node &b) {
    if (a.num == b.num) return a.num < b.num;
    return a.num < b.num;
}

int main() {
    map<string, int> m;
    scanf("%s", s);
    string str;
    for(int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            m[str] += 1;
            str.clear();
        }
        str += s[i];
        
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        //cout << it->first << " " << it->second << endl;
        x[cnt].str = it->first;
        x[cnt].num = it->second;
        cnt++;
    }
    sort(m.beign(), m.end(), cmp());


    return 0;
}

