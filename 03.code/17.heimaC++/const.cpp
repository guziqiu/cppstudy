#include <iostream>
using namespace std;

void test5()
{
	const int a = 10;
	int *p = (int *)&a; //对常量取地址，编译期会对常量取零时空间生成零时地址
	*p = 70;
	cout << "a " << a << endl;
	cout << "*p " << *p << endl;
}

int main()
{
	test5();
}