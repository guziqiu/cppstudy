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
    queue<int> que;
    int n, mod;
    cin >> n >> mod;
    for (int i = 0; i < n; i++) {
        que.push(i + 1);
        //cout << i + 1 << " ";
    }
    //cout << endl;
    int num = 0;
    while (que.size() > 1) {
        num++;
        if (num == mod) {
            //cout << que.front() << " ";
            num = 0, que.pop();
            continue;
        } 
        int temp = que.front();
        que.pop();
        que.push(temp);
    }
    cout << que.front() << endl;
    
    return 0;
}

