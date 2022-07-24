#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class MyString
{
public:
	MyString(char *tmp = "abc")
	{
		len = strlen(tmp); 
		str = new char[len + 1]; 
		strcpy(str, tmp); 

		cout << "普通构造函数: tmp = " << tmp << endl;
	}
	// 移动构造函数
	// 参数是非const的右值引用
	MyString(MyString && t)
	{
		str = t.str; // 拷贝地址，没有重新申请内存
		len = t.len;

		// 原来指针置空
		t.str = nullptr;
		cout << "移动构造函数。。。" << endl;
	}

	MyString(const MyString &tmp)
	{ 
		len = tmp.len;
		str = new char[len + 1];
		strcpy(str, tmp.str);
		cout << "拷贝构造函数: tmp.str = " << tmp.str << endl;
	}

	MyString &operator=(const MyString &tmp)
	{ 
		if (&tmp == this)
		{
			return *this;
		}

		
		len = 0;
		delete[] str;

		
		len = tmp.len;
		str = new char[len + 1];
		strcpy(str, tmp.str);

		cout << "赋值运算符重载: tmp.str = " << tmp.str << endl;

		return *this;
	}

	// 移动赋值函数
	// 参数为非const的右值引用
	MyString &operator=(MyString &&tmp)
	{
		if (this == &tmp)
		{
			return *this;
		}

		// 先释放原来的内存
		// len = 0;
		delete []str;

		// 无需重新申请堆区内存
		len = tmp.len;
		str = tmp.str;

		tmp.str = nullptr;
		tmp.len = 0;
		cout << "移动赋值函数。。。" << endl;

		return *this;
	}

	~MyString()
	{ 
		cout << "析构函数 " << endl;
		if (nullptr != str)
		{
			cout << "已操作 delete str = " << str << endl;
			delete[] str;
			str = nullptr;
			len = 0;
			
		}
	}
public:
	char *str = nullptr;
	int len = 0;
};

MyString func() 
{
	MyString obj("mike");  // 2.调用普通构造函数

	cout << "&obj mike = " << (void *)&obj << endl;

	return obj;  // 3.通过移动构造函数生成一个新的临时对象
}

//g++ 51.move_assign.cpp -fno-elide-constructors -std=c++11 
// 普通构造函数: tmp = abc
// 普通构造函数: tmp = mike
// &obj mike = 0x7ff7b5c36878
// 移动构造函数。。。
// 析构函数 
// 赋值运算符重载: tmp.str = mike
// 析构函数 
// 已操作 delete str = mike
// &str mike =0x7ff7b5c368e8
// 析构函数 
// 已操作 delete str = mike

// 添加移动赋值函数

// 普通构造函数: tmp = abc
// 普通构造函数: tmp = mike
// &obj mike = 0x7ff7bc3de878
// 移动构造函数。。。
// 析构函数 
// 移动赋值函数。。。
// 析构函数 
// &str mike =0x7ff7bc3de8e8
// 析构函数 
// 已操作 delete str = mike

// 只delete一次


int main()
{
	MyString str("abc"); // 实例化一个对象     1.调用普通构造函数
	
	str = func();  //右值引用 4.新的临时对象给str赋值，赋值运算符重载函数
	// 5.func调用完毕，obj释放，调用析构函数，无需delete
	// 6、赋值完成后，临时对象生命周期结束，同样需要析构函数，需要delete
	// main调用完毕，析构str

	cout << "&str " << str.str << " =" << (void *)&str << endl;

	return 0; 
}