#include <iostream>
using namespace std;
void func(int x) {
    for (int i = 0; i < x; i++)   cout << i << endl;
    return ;
}


void add(int a, int b) {
    cout << a << " + " << b << endl;
    return ;
}

void test_ref(int &x) {
    x = 1;
    cout <<  "test_ref function" << endl;
}

int main() {
    
    cout << "========" << endl;
    auto add3 = bind(add, 3, std::placeholders::_1); // bind完成部分参数绑定, 预留槽位 
    // placeholders 参数占位符 
    // 
    add3(45);
    add3(89);
    add3(100);

    cout << "===" << endl;
    auto add2  = bind(add, std::placeholders::_1, std::placeholders::_2);
    add2(3, 4);
    
    auto add4  = bind(add, std::placeholders::_2, std::placeholders::_1);
    add4(3, 4);
    // 参数占位符
    // bind(function, 1, 2)
    // 1 ： 新函数中第一个参数
    // 2 ： 新函数第二个参数
    
    cout << "===" << endl;

    int n = 0;
    // auto ref_func = bind(test_ref, n);   //                     0  0
    auto ref_func = bind(test_ref, ref(n)); // 显示性的调用引用    0  1
    cout << n << endl;
    ref_func();
    cout << n << endl;

    cout << "=========function ========" << endl;
    

    // function高级函数指针对象 可以指向任意可调用对象   bind一般配合function使用
    // <void()> 返回void类型，()没有参数
    // y一个负责绑定函数，一个负责返回值类型
    function<void()> f = bind(func, 123);
    f();

    cout << "===" << endl;
    function<void(int)> add5 = bind(add, 3, std::placeholders::_1);
    add5(3);
    add5(45);

    function<void(int, int)> add6 = bind(add, std::placeholders::_2, std::placeholders::_1);
    add4(3, 4);
    
    cout << "===" << endl;

    function<void()> ref_func1 = bind(test_ref, ref(n)); // 显示性的调用引用    0  1
    cout << n << endl;
    ref_func1();
    cout << n << endl;

    cout << "=========" << endl;
 






    return 0;
}

