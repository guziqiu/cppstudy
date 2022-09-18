#include <iostream>
#include <chrono>
using namespace std;

int main()
{
	auto a = 1'234'567; // 1234567 整数
	auto b = 1'234'56s; // 1234567秒 // std::chrono::milliseconds

	cout << a << endl;
	cout << b.count() << endl;
	return 0;
}
