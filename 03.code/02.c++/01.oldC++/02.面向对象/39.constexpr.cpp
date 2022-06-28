#include <iostream>
using namespace std;



constexpr int f(int x) {
    return x * x;
}

class A {
public :
    constexpr A(int x) {}
};


int main() {

    int n;
    cin >> n;
    const int a = n + 123; // 运行期常量
    constexpr int y1 = 123; // 
    constexpr int y2 = f(123);
    const A a1(123);
    constexpr A a2(123);
    
    // const 运行期常量
    // constexpr 编译期常量 叫作表达式常量
    
    
    const int x = 123;
    constexpr int y = 123;
    
    // 都会报错
    // x = 456;
    // y = 456;


    *(const_cast<int *>(&x)) = 456; // 转换常量
    *(const_cast<int *>(&y)) = 456; // 转换常量
    cout << x << endl;
    cout << y << endl;
    cout << const_cast<int *> (&x) << endl;
    cout << const_cast<int *> (&y) << endl;
    cout << &x << endl;
    cout << &y << endl;
    cout << *(&x) << endl; // & 取地址是运行期的，躲避了编译期优化
    cout << *(&y) << endl; // & 取地址是运行期的，躲避了编译期优化




    
    return 0;
}

