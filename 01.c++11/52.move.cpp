#include <iostream>
using namespace std;
int main()
{
	int a = 10; // a 为左值
	// int && b = a;  // err, 左值不能绑定到右值引用

	int && c = std::move(a); // move 将一个左值转换成右值
	cout << "c = " << c << endl;

	return 0;
}