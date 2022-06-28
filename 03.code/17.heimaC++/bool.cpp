#include <iostream>

int g_val; // bss段，默认0
using namespace std;

struct student
{
	char name[64];
	int id;
};

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

void test4()
{
	int a = 10;
	int b = 20;
	int c = 0;

	// c
	//左值 右值
	c = a < b ? a : b;
	cout << c << endl;

	*(a < b ? &a : &b) = 50;
	cout << "a = " << a << endl;
	// c++ 
	((a < b) ? a : b) = 60;
	cout << "b = " << b << endl;
}

int main()
{
	test4();
	return 0;
	test1();

	return 0;

	int a = 10;
	int b; // 随机值
	cout << g_val << " " << a << " " << b << endl;
	return 0;

	// struct 

}