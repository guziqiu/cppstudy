#include <iostream>
using namespace std;

void func(int x) {
    cout << x << endl;
    return ;
}

void add(int a, int b) {
    cout << a << " + " << b << endl;
    return ;
}

int main() {

    func(123);
    func(123);
    func(123);
    func(123);
    func(123);

    auto f = bind(func, 123);
    cout << "=========" << endl;

    f();
    f();
    f();
    f();
    f();

    cout << "========" << endl;
    auto add3 = bind(add, 3, std::placeholders::_1); // bind完成部分参数绑定, 预留槽位 
    // placeholders 参数占位符 
    // 
    add3(45);
    add3(89);
    add3(100);

    
    return 0;
}

