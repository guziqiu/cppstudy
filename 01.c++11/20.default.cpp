#include <iostream>
using namespace std;

class X
{
public:
	X() = default; // 让编译器提供一个默认的构造函数，效率比用户写的的高

	X(int i)
	{
		// 写了带参数的构造函数，编译器就不会提供无参的构造函数
		a = i;
	}

	int a;
};

// default 只能修饰类中默认提供的构造函数，无参构造，拷贝构造,赋值运算符重载，析构函数等
#if 0
class X2
{
public:
	int f() = default;
	X2(int a) = default;
};
#endif

class X3
{
public:
	X3(); // 声明
	X3(int a) {}
};

X3::X3() = default; // default可以放在类的外部

int main()
{
		X obj;


	return 0;
}