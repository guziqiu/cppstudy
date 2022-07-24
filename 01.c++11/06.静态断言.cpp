#include <iostream>
#include <cassert>
using namespace std;

void test()
{
	bool flag = false;

	// 运行时 检查条件 
	// 如果条件为真，往下执行
	// 如果条件为假，中断，提示错误
	// assert(true == flag);
	assert(false == flag);
	cout << "hello c++ 11" << endl;

	// c++ 11 静态断言
}

void test1()
{
	// static_assert(常量表达式, "提示的字符串")
	
	cout << sizeof(void *) << endl;
	// static_assert(sizeof(void *) == 4, "64位系统不支持"); // 编译报错
	static_assert(sizeof(void *) == 8, "64位系统不支持");
	cout << "hello c++ " << endl;
}


int main() {
	// test();
	test1();

	return 0;
}
