#include <iostream>
using namespace std;

// 继承方式展开可变参数模板类
// 1.可变参数模板类声明
// 2.递归继承模板类
// 3.边界条件

// 1.声明
template<class ...T> class Car{}; // 必须有声明

// 2.递归继承模板类
template<class Head, class ... Tail>
class Car<Head, Tail...> : public Car<Tail...> // 递归继承本身
{
public:
	Car()
	{
		cout << "type = " << typeid(Head).name() << endl;
	}
};

// 3.边界条件
template<> class Car<> {};

int main() {
	Car<int, char *, double> c;
	return 0;
}
