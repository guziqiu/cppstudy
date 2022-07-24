#include <iostream>
using namespace std;

class A1
{
public:
	// 这个是基类，是第一个虚函数，不能重写。不能用override修饰
	virtual void func(int a) //override
	{

	}
};

class A2: public A1
{
public:
	// 在重写虚函数的地方，加上override,要求重写的虚函数和基类的一模一样
	virtual void func(int a) override
	{

	}
};

int main()
{


	return 0;
}