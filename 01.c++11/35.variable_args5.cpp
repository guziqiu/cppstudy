#include <iostream>
using namespace std;

// 1.变长模版声明
// 2.变长模板类定义
// 3.边界条件

// 1.声明
template<int... last> class Test {};

// 2.类定义
template<int first, int ... last>
class Test<first, last ...>
{
public:
	static const int val = first * Test<last ...>::val;
};

// 3.边界条件
template<>
class Test<>
{
public:
	static const int val = 1;
};

int main() {
	cout << Test<2, 3, 4, 5>::val << endl;
	// first 2 last 2 3 4
	// 2 * 3 * 4 * 1

	return 0;
}
