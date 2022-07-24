#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	A(int i) : a(i) // 参数列表初始化
	{}

public:
	int a;
};

class B 
{
public:

public:
	int data1 {1};
	int data2 = 1;
	A tmp {10};
	string name {"string"};
};

void test()
{
	B obj;
	cout << obj.data1 << endl;
	cout << obj.data2 << endl;
	cout << obj.name << endl;
}

int main() {
	test();

	return 0;
}
