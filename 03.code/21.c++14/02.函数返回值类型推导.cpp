#include <iostream>
using namespace std;

template<typename T>
auto func(T i)
{
	return i;
}

int main()
{
	cout << func("C++14") << endl;
	return 0;
}