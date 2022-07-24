#include <iostream>
#include <functional> // std::function
using namespace std;
void func(int x, int y)
{
	cout << x << " " << y << endl;
}

int main()
{
	bind(func, 11, 22) (); // 输出 11 22
	cout << "---" << endl;

	// std::placeholders::_1  函数调用时，被第一个参数替换
	// std::placeholders::_2  函数调用时，被第二个参数替换

	bind(func, std::placeholders::_1, std::placeholders::_2) (11, 22); // 输出 11 22
	cout << "---" << endl;

	using namespace std::placeholders;
	bind(func, 11, _1) (22, 33, 44); // 输出11 22 ， 后面的33 44 没有作用
	cout << "---" << endl;

	bind(func, _2, _1) (11, 22); // 输出 22 11
	cout << "---" << endl;

	// bind(func, _2, 22) (11); // err 没有第二个参数
	bind(func, _2, 22) (11, 0);  //输出 0 22
	bind(func, _3, 22) (11, 0, 33);  //输出 33 22

	return 0;
}