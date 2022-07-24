#include <iostream>
using namespace std;

int tmp = 1;

class Test
{
public:
	int i = 0;

	void func()
	{
		int a = 10;
		// err, []为空，没有捕获任何变量
		// auto f1 = []() { cout << i << endl; };

		auto f1 = [=]() { cout << i << endl; };
		auto f2 = [&]() { cout << i << endl; };

		// this 只是捕获类成员变量 全局变量,但是不能捕获局部变量
		auto f3 = [this]()
		{
			cout << i << endl;
			cout << tmp << endl;
			// cout << a << endl; 
		};
	}
};

int main()
{
	int a = 0;
	int b = 0;

	auto f1 = [] () {};

	// a, b 以值传递的方式
	auto f2 = [a, b] () { cout << a << ", " << b << endl; };
	f2();
	cout << "-----" << endl;

	// [] 里面捕获的是外面的属性，()里面穿的是参数
	auto f3 = [a, b] (int x, int y)
	{ 
		cout << a << ", " << b << endl;
		cout << "x = " << x << ", y = " << y << endl;
	};
	f3(1, 2);
	cout << "-----" << endl;

	// 以值传递的方式传给lambda表达式
	auto f4 = [=] { cout << a << ", " << b << endl; };
	f4();
	cout << "-----" << endl;

	// 以引用的方式捕获外面的变量
	auto f5 = [&] { cout << a << ", " << b << endl; };
	f5();
	cout << "-----" << endl;

	// a以值传递，其他以引用方式传递
	auto f6 = [&, a] () { cout << a << ", " << b << endl; };
	f6();
	cout << "-----" << endl;

	// a以引用，其它值传递
	auto f7 = [=, &a] () { cout << a << ", " << b << endl; };
	f7();
	cout << "-----" << endl;

	// 默认情况下，lambda函数，以const修饰函数体，值传递无法修改，想修改必须加mutable
	auto f8 = [=] () mutable
	{
		a++; cout << a << ", " << b << endl;
	};
	f8();
	cout << "-----" << endl;


	auto f9 = [=] () mutable
	{
		cout << tmp << endl;
	};
	f9();
	cout << "-----" << endl;


	return 0;
}