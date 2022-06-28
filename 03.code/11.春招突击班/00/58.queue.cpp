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
    
    que.push(2);
    que.push(3);
    que.push(5);

    cout << que.size() << endl;
    cout << que.front() << endl;
    cout << que.back() << endl << endl;
    while (!que.empty()) {
        cout << que.front() << endl;
        que.pop();
    }


    return 0;
}

