#include <iostream>
using namespace std;

class X
{
public:
	X() {} //普通无参
	// X(const X &) {}// 拷贝构造
	X(const X &) = delete; // 拷贝构造，用delete 修饰，此函数被禁用
	// X & operator=(const X &) { return *this; } // 运算符重载函数
	X & operator=(const X &)= delete; // 赋值运算符重载函数，用delete修饰，此函数被禁用

	X(int ) = delete; // 用=delete修饰，此函数被禁用

	// void *operator new(size_t) = delete;  // 无法 = new
	void *operator new[](size_t) = delete; /// X *p = new X[10];
};


int main()
{
	X obj1; // 普通无参
	X obj2;// = obj1; //拷贝构造

	// obj2 = obj1; // 赋值运算符重载函数

	// X obj(10);

	X *p = new X;

	return 0;
}