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

int main() {
    queue<int> man, woman;
    int x, y, n;
    cin >> x >> y >> n;
    for (int i = 0; i < x || i < y; i++) {
        if (i < x) man.push(i + 1);
        if (i < y) woman.push(i + 1);
    }
    
    for (int i = 0; i < n; i++) {
        cout << man.front() << " " << woman.front() << endl;
        int temp1 = man.front(), temp2 = woman.front();
        man.pop(), man.push(temp1);
        woman.pop(), woman.push(temp2);
    }



    
    return 0;
}

