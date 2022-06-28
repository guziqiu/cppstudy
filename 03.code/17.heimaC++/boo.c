#include <stdio.h>
void test4()
{
	int a = 10;
	int b = 20;
	int c = 0;

	// c
	//左值 右值
	c = a < b ? a : b;
	pritnf("c = %d\n", c);

	*(a < b ? &a : &b) = 50;
	// cout << "a = " << a << endl;
	// c++ 
	((a < b) ? a : b) = 60;
	// cout << "b = " << b << endl;
}
int main()
{

	test4();
	return 0;
}