#include <iostream>
using namespace std;

#define func(x) __func(x, "func("#x")")
#define func2(x) __func2(x, "func2("#x")")

void __func2(int &x, const char *str) {
    // 判断是左值引用还是右值引用
    cout << str << " is left value" << endl;
    return ;
}
void __func2(int &&x, const char *str) {
    // 判断是左值引用还是右值引用
    cout << str << " is right value" << endl;
    return ;
}

void __func(int &x, const char *str) {
    // 判断是左值引用还是右值引用
    cout << str << " is left value" << endl;
    func2(x);
    return ;
}

void __func(int &&x, const char *str) {
    cout << str << " is right value" << endl;
    func2(forward<int &&>(x));
    return ;
}

class A {
public :
    A operator+(int x) {}   // 应该返回右值，返回值
    A &operator+=(int x) {} // 应该返回左值类型，所以返回了应该引用
};



int main() {
    
    int x = 1234, y = 456;
    int &rx = x; // 左值引用

    func(1234);
    func(x);
    func(x + y);
    func(x++);
    func(++x);
    func(x + 123);
    func(x += 123);
    func(x *= 2);
    func(y += 3);
    func(y * 3);




    return 0;
}

