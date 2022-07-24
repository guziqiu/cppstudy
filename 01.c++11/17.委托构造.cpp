#include <iostream>
using namespace std;

class Test
{
public:
	// 委托构造，一定要挺过初始化列表方式
	Test() : Test(1, 'a')
	{

	}

	Test(int x) : Test(x, 'b')
	{

	}

	Test(char x) : Test(11, x)
	{

	}
private:
	Test(int x, char y) : a(x), b(y)
	{

	}

public:
	int a;
	char b;
};

int main()
{
	{
		Test obj;
		cout << obj.a << ", ";
		cout << obj.b << endl;
	}

	{
		Test obj(10);
		cout << obj.a << ", ";
		cout << obj.b << endl;
	}

	{
		Test obj('c');
		cout << obj.a << ", ";
		cout << obj.b << endl;
	}


	return 0;
}