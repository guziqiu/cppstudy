#include <iostream>
using namespace std;

// 可变参数模版
template<class ... T> // T 叫模版参数包
void func(T ... args) // args 叫函数参数包
{
	cout << sizeof...(args) << endl;
}


int main()
{
	func<int>(10);
	func(11);
	func<int, int>(10, 20);
	func<char, int>(10, 'a');
	func<char, char *, int>('2', "a", 250);

	return 0;
}