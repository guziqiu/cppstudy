#include <iostream>
#include <stack>
using namespace std;

void test1() {
    stack<int> s, s2(s);
    // stack操作
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(100);
    //cout << "top : " << s.top() << endl;
    while (!s.empty()) {
        cout << "top : " << s.top() << endl;
        s.pop();
    }
    cout << "size :" << s.size() << endl;
    
}
// 栈不能遍历,不支持随机存储

int main() {
    test1();

    return 0;
}
