#include <iostream>
using namespace std;

template<class T>
void print(T tmp)
{
	cout << tmp << endl;
}


// 可变参数的模版函数
// 参数包展开函数
template<class ...T>
void func(T... args)
{
	// 逗号运算符
	// 初始化列表
	int a[] = {(print(args), 0) ...};
}

int main() {
	func(1, 2, 3, 4);
	func('1', "2", 3.1, 4);
	//只能是相同类型
	return 0;
}
