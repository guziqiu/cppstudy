#include <iostream>

using namespace std;

int GetNum()
{
	return 2;
}

const int GetNum2()
{
	return 3;
}

constexpr int GetNum3()
{
	// 常量表达式发生在编译阶段
	return 3;
}

int main()
{
	// error: expression is not an integral constant expression
	// 枚举成员初始化必须是整型常量
	// enum {e1 = GetNum(), e2}; // 枚举

	// enum {e1 = GetNum2(), e2};

	enum {e1 = GetNum3(), e2};
	constexpr int tmp = GetNum3(); //ob,发生在编译阶段

	enum {e3 = tmp};
	cout << tmp << endl;

	cout << e3 << endl;

}