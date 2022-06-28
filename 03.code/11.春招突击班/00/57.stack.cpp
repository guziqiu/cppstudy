#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> sta;
    sta.push(5);
    sta.push(10);
    sta.push(-2);
    cout << sta.size() << endl;
    cout << sta.top() << endl;
    
    while (!sta.empty()) {
        cout << sta.top() << endl;
        sta.pop();
    }


    return 0;
}

