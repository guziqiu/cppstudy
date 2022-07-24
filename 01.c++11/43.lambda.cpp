#include <iostream>
using namespace std;

void test1()
{
	int a;

	// lambda表达式，新建一个变量，外部变量给这个赋值一份，值传递
	auto f1 = [=]() mutable
			{
				cout << "a1 = " << a << endl;
				a = 111;
				cout << "a2 = " << a << endl;
			};

	f1();
	cout << "----" << endl;

	cout << "a3 = " << a << endl;
	a = 222;
	f1();
}

void test2()
{
	int b = 10;
	auto f = [&]()
		{
			b = 111;
			cout << "b = " << b << endl;
		};
	
	f();

	cout << "b = " <<  b << endl;
}

int main()
{
	test1();
	test2();

}