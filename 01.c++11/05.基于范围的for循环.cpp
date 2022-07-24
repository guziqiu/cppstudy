#include <iostream>
using namespace std;

void test()
{
	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(*a);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// c++ 11
	for (auto i : a)
	{
		cout << i << " ";
	}
	cout << endl;

	// 取引用
	for (auto &i : a)
	{
		i *= 2;
		cout << i << " ";
	}
	cout << endl;
}

void func(int *a) // 形参中数组不是数组， 是指针变量，无法确定元素个数
{
	// 基于范围的for， 这个范围是确定的，否则无法使用
	for (auto tmp : a)
	{
		cout << tmp << endl;
	}
}

int main()
{
	test();

	return 0;
}
