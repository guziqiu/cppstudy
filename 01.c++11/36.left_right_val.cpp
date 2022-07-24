#include <iostream>
using namespace std;

void test01()
{
	// 左值放左边。右值放右边
	// 左值可以放&， 右值不能放&
	int a = 10;
	// 右值 字面量 函数返回的非引用变量
}

void test02()
{
	// 引用: 给一个内存取一个别名，定义时必须初始化
	// 左值引用
	int a;
	int &b = a;
	// int &c = 1; // err
	const int &d = a; // ok
	const int &e = 1;
}

int & func()
{
	static int tmp;
	return tmp;
}

void test3()
{
	int &f1 = func();
	const int &f = func();
}

// const int & 万能引用

int func02() { return 10; }
void test4()
{
	// 右值引用
	int && a = 10;
	int && b = func02();
	int j = 10;
	int i = 20;
	int && c = i + j;

	int k = 10;
	// int && d = k; // err 不能把一个左值赋值给右值引用
}

void f1(int &tmp)
{
	cout << "左值引用 = " << tmp << endl;
}

void f1(int &&tmp)
{
	cout << "右值引用 = " << tmp << endl;
}

void test5()
{
	int a = 10;
	f1(a);
	f1(100);
}


int main()
{
	test5();
	return 0;
}