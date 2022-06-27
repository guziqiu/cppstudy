## 1.C++ namespace



```c++
#include <iostream>
using namespace std;

namespace spaceA {
	int g_a = 10;

	namespace spaceB {
		struct teacher
		{
			int id;
		};
	}
}



int main()
{
	cout << spaceA::g_a << endl;

	// 1
	// spaceA::spaceB::teacher t1;
	// using spaceA::spaceB::teacher;

	// 2
	// teacher t1;
	using namespace::spaceA::spaceB;
	// teacher t1;
	// 2
	struct teacher t1;
	t1.id = 10;
	cout << t1.id << endl;


}
```



## 2.C++ bool



```c++
// bool 0 falses
// bool  1  true
// 其他值会转换为1， 大小为1个字节
void test1()
{
	bool flag = true;
	cout << flag << endl;
	flag = -100;
	cout << flag << endl;
	cout << sizeof(flag) << endl;
}
```



## 3.C++三目运算符

```c++
void test4()
{
	int a = 10;
	int b = 20;
	int c = 0;

	// c
	//左值 右值
	c = a < b ? a : b;
	cout << c << endl;
  
	//((a < b) ? a : b) = 60;// error: expression is not assignable
	*(a < b ? &a : &b) = 50;
	cout << "a = " << a << endl;
 
	// c++ 
  c = a < b ? a : b;
	cout << c << endl;
	((a < b) ? a : b) = 60;
	cout << "b = " << b << endl;
}
```



4.c++ const



```c++
void test5()
{
	const int a = 10;
	int *p = (int *)&a; //对常量取地址，编译期会对常量取零时空间生成零时地址
	*p = 70;
	cout << "a " << a << endl;
	cout << "*p " << *p << endl;
}s
```











