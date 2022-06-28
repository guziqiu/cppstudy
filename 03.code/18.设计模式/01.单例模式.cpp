#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class A {

private :
	A() {}

public :
	static A* getInstace()
	{
		return a;
	}
private :
	static A *a;
};

	// 如何实现单例：
	// 1. 构造函数私有化
	// 2. 增加静态私有化的当前类的指针变量
	// 3. 提供一个静态的对外接口，让用户可以获得单例对象

	// 单例分为懒汉式 和 饿汉式
// 懒汉式
class singleton_lazy {
private :
	singleton_lazy() { plazy = nullptr;}
public : 
	static singleton_lazy *getInstace()
	{
		if (nullptr == plazy)
		{
			plazy = new singleton_lazy();
		}
		return plazy;
	}
private :
	static singleton_lazy *plazy;
};
// 类外初始化
singleton_lazy* singleton_lazy::plazy = nullptr;

// 饿汉式

class singleton_hungry {
private :
	singleton_hungry() { pHungry = nullptr; cout << "i am hungry!\n" << endl;}
public : 
	static singleton_hungry *getInstace()
	{
		return pHungry;
	}
#if 0
	// 不合适
	static void freeSpace()
	{
		if (pHungry != NULL)
		{
			delete pHungry;
		}
	}
#endif
	class garbo {
		~garbo()
		{
			if (pHungry != nullptr)
			{
				delete pHungry;
			}
		}
	};
private :
	static singleton_hungry *pHungry;
	static garbo garbo;
};

// 类外初始化
singleton_hungry* singleton_hungry::pHungry = new singleton_hungry;

// 单例对象释放问题
// 不需要考虑
void test1()
{
	singleton_lazy *p1 = singleton_lazy::getInstace();
	singleton_lazy *p2 = singleton_lazy::getInstace();

	if (p1 == p2)
	{
		cout << "same memory, is singleton" << endl;
	}
	else{
		cout << "not singleton" << endl;
	}

	singleton_hungry *p3 = singleton_hungry::getInstace();
	singleton_hungry *p4 = singleton_hungry::getInstace();
	if (p3 == p4)
	{
		cout << "same memory, is singleton" << endl;
	}
	else{
		cout << "not singleton" << endl;
	}
	
}

void test2()
{

}

int main() {
	// A::getInstace();

	cout << "main begin ..." << endl;
	test1();

	return 0;
}
