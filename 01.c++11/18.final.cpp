#include <iostream>

// 阻止类的进一步派生，虚函数的进一步重写
#if 0
class A1 final
{
	int a;
};

class A2: public A1 //err 基类不能再派生了
{
	
};
#endif

// 基类
class B1
{
public:
	virtual void func() final{} // 这是最终版本的虚函数，不能再重写，
};
// 派生类冲洗基类分粗函数
class B2: public B1
{
	//error: declaration of 'func' overrides a 'final' function
	// virtual void func(); //基类的虚函数无法重写
};


int main()
{


	return 0;
}