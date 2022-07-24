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
void example3() {
 int i = 0;
	auto *a = &i;
	cout << a << endl;
	cout << *a << endl;

	auto &b = i;
	cout << b << endl;
}

void example4() {
	int a = 0, b = 0;
	decltype(a + b) c =  11; // c 是 int, 因为(a + b)返回一个右值
	cout << c << endl;

	decltype(a += b) d = c; // d 是 int, 因为(a + b)返回一个左值

	d = 20;
	cout << "c = " << c << endl;
}

// template<typename T, typename U>
// return_value add(T t, U u) { // t 和 u 类不确定，无法推导出return_value类型
// 	return t + u;
// }


// template<typename T, typename U>
// decltype(t + u) add(T t, U u) { // t 和 u 尚未定义 error编译报错
// 	return t + u;
// }

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
	return t + u;
}


void example5() {
	cout << add(1, 2) << endl;
	cout << add((string)"asd", (string)"asd") << endl;
}


int main() {
	example5();
	return 0;

   example4();
//    cout << i << endl;

const int &i = 1;
int a = 2;
decltype(i) b = 2;

cout << i << endl;

    return 0;
}