#include <iostream>
using namespace std;

// 仿函数 重载operator
class MyFunctor
{
public:
	MyFunctor(int tmp) : round(tmp) {} //构造函数

	// 仿函数 重载operator()
	int operator()(int tmp) { return tmp + round; }

private:
	int round;
};

int main()
{
	//仿函数的调用
	int round = 2;
	MyFunctor f1(round);//调用构造函数
	cout << "result1 = " << f1(1) << endl; //operator()(int tmp)

	//lambda表达式
	auto f2 = [=](int tmp) -> int { return tmp + round; } ;
	cout << "result2 = " << f2(1) << endl;

	return 0;
}
