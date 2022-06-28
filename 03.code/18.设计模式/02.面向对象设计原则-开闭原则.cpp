#include <iostream>
using namespace std;
// 开闭原则 对扩展开放，对修改关闭，增加功能是通过增加代码进行实现的,而不是修改代码

// 抽象类 计算器

class AbstractCaculator
{
public :
	virtual int getResult() = 0;
	virtual void setop(int a, int b) = 0;
};

// 加法

class Plus : public AbstractCaculator
{

public:
	virtual void setop(int a, int b)
	{
		this->m_a = a;
		this->m_b = b;
	}
	virtual int getResult()
	{
		return this->m_a + m_b;
	}

	int m_a;
	int m_b;
};

// 减法

int main() {

	AbstractCaculator *cal = new Plus;
	cal->setop(10, 20);
	cout << cal->getResult() << endl;


	return 0;
}
