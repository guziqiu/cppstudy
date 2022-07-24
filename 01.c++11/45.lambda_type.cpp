#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

int main()
{
	function<int(int)> f1 = [] (int a) { return a + 1; };
	cout << f1(11) << endl;

	function<int(int)> f2 = bind(
		[] (int a) { return a + 1; },
		_1
	);

	cout << f2(9) << endl;

	auto f4 = [] (int x, int y) -> int { return x + y; };
	cout << f4(1, 2) << endl;

	decltype (f4) tmp = f4;
	cout << tmp(2, 2) << endl;

	// 定义一个函数指针类型
	typedef int (*PFUNC)(int, int);
	PFUNC p1 = f4; // lambda转换为函数指针， ok  类型、参数、返回值必须保持一致 不允许捕获外部变量
	cout << p1(10, 10) << endl;

	// decltype f4 = p1; // err 函数指针转换为lambda表达式

	return 0;
}
