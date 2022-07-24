#include <iostream>
using namespace std;

// 递归终止函数
#if 0
void func()
{
	cout << "empty" << endl;
}

#endif
// 方法二：
template<class T>
void func(T tmp)
{
	cout << "tmp: " << tmp << endl;
}


// 可变参数的模版函数
// 参数包展开函数
template<class T1, class... T2>
void func(T1 first, T2... second)
{
	cout << first << endl;
	cout << sizeof...(second) << endl;

	// 递归调用函数本身
	func(second ...);
}

int main() {
	func(1);
	func(1, 2, 3, 4);
	#if 0
	// 相当于递归调用
	func(1, 2, 3, 4);
	func(2, 3, 4);
	func(3, 4);
	func(4);
	func();
	#endif

	// func(1, "asd", 3.11, true);

	return 0;
}
