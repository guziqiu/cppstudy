#include <iostream>
using namespace std;

// c++11 引入了auto 和 decltype 关键字，
// 使用他们可以在编译期就推导出变量或者表达式的类型

// auto : 让编译器在编译期就推导出变量的类型，
// 可以通过=右边的类型推导出变量的类型

// 1.基本用法
void example1() {
    auto a = 1;
    // 1 是int类型，可以自动推导出a是int
}

// 2.error auto 不能用作函数参数
// void func(auto value) {}

class A {
    // error: non-static data member declared with placeholder ‘auto’
    // auto a = 1; // 在类中auto不能用作非静态成员变量
    // error: ISO C++ forbids in-class initialization of non-const static member
    // static auto b = 1; // 这里与auto无关，正常static int b = 1 也不可以
    static const auto c = 1; //  ok
};

// decltype : 相对于auto用户推导出变量类型，
// 而decltype则用于推导表达式类型，
// 这里只用于编译器分析表达式的类型，
// 表达式实际不会进行运算

void example2() {
    const int &i = 1;
    int a = 2;
    decltype(i) b = 2; // b 是 const int&
}



int main() {

    



    return 0;
}