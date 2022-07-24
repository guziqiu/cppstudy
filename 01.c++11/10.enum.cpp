#include <iostream>
using namespace std;

void test1()
{
	// 以前枚举的局限性
	enum Status {ok, error};
	// enum status2 {ok, error}; // 编译不通过 
	cout << sizeof(ok) << endl; // 大小和int类型大小一样
	cout << sizeof(int) << endl;
}

void test2()
{
	// 强枚举类型 enum后面加上class 或者struct修饰
	enum class Status {ok, error};
	enum class status2 {ok, error};

	// Status flag = ok;   // err,必须枚举类型的作用域
	Status flag = Status::ok; // ok

	// 强枚举类型可以指定成员变量的类型
	enum struct Status3:char {ok, error};
	cout << sizeof(Status3::ok) << endl; // 1

	enum struct Status4:long long {ok, error};
	cout << sizeof(Status4::ok) << endl; // 8

}



int main() 
{
	test1();
	test2();


	return 0;
}
