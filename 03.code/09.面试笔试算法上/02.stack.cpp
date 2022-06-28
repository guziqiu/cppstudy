#include <iostream>
#include <stack>
using namespace std;

int main() {
    
    stack<int> s;
    for (int i = 9; i > 4; i--) {
        s.push(i);
    }
    while (s.size()) {
        //!s.empty()
        cout << "s.top() = " << s.top() << "\t s.size() = " << s.size() <<  endl;
        s.pop();
    }



    return 0;
}

