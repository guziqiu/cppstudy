#include <iostream>
using namespace std;

void func2(int &x) {
    cout << __PRETTY_FUNCTION__ << "called" << endl;
}

void func2(const int &x) { // 可以绑定任意版本
    cout << __PRETTY_FUNCTION__ << "called" << endl;
}

void func2(int &&x) {
    cout << __PRETTY_FUNCTION__ << "called" << endl;
}

void func2(const int &&x) {
    cout << __PRETTY_FUNCTION__ << "called" << endl;
}


int main() {
    int n;
    const int y = 123; 
    // 优先绑定到最匹配的上面
    func2(n); // func2(int &) // 优先绑定到左值引用
    func2(y); // func2(const int &) 
    func2(123 + 456); // func1(int &&)
    // func1(const int &&)
        
    return 0;
}

