#include <iostream>
using namespace std;

// 1.普通函数的默认参数
void func(int a = 3) {}

// 2.类模板 支持默认的模版参数
template<class T = int>
class A
{

};

// template<class T = int, class T2> // 类模板的模版参数必须是从右往左
// class A1
// {

// };

template<class T = int, class T2 = int> // 类模板的模版参数必须是从右往左
class A2
{

};

// 3. c++ 11 才支持，函数模版 带默认的模版参数
template<class T = int>
void func(T a) {}

// 3. c++ 11 才支持，函数模版 带默认的模版参数
template<class T = int, class T1> // 函数参数的参数模版可以是从右往左，也可以是从左往右
void func1(T a) {}

template<class T, class T1 = int> // 函数参数的参数模版可以是从右往左，也可以是从左往右
void func1(T a) {}


int main() {


	return 0;
}
