#include <iostream>
using namespace std;

void func(int a)
{
	cout << __LINE__ << endl;
}

void func(int *p)
{
	cout << __LINE__ << endl;
}

int main() {


	int *p = NULL;
	int *p2 = 0;
	int *p3 = nullptr;
	// nullptr 只能给指针赋值
	// int p4 = nullptr; // 编译报错

	if (p == p2)
	{
		cout << "NULL == 0" << endl;
	}

	if (p3 == p2)
	{
		cout << "nullptr == 0" << endl;
	}

	if (p == p3)
	{
		cout << "nullptr == NULL" << endl;
	}


	func(0);
	// func(NULL);
	func(p);
	func(nullptr);

	return 0;
}
