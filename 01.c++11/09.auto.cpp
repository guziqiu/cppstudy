#include <iostream>
#include <set>
using namespace std;

class Demo
{
public:
	using set_type = std::set<int>; // 集合类型别名
private:
	set_type m_set;              //使用类型别名定义变量

	// 使用decltype 计算表达式的类型
	using iter_type = decltype(m_set.begin());

	iter_type m_pos;// 类型别名定义成员变量
};


int main() {


	return 0;
}
