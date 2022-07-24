#include <iostream>
using namespace std;

void func1()
{
	throw 1;
}

// 这个函数不能抛出任何异常
// c++11 已经弃用 throw 0
void func2() throw()
{
	// throw 0;
}

// 这个函数不能抛出任何异常
// c++11 用noexcept代替 throw()
void func3() noexcept
{

}

int main() {


	return 0;
}
