#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class MyString
{
public:
	MyString(char *tmp = "abc")
	{ // 普通构造函数
		len = strlen(tmp); // 长度
		str = new char[len + 1]; // 堆申请空间
		strcpy(str, tmp); // 拷贝内容

		cout << "普通构造函数: tmp = " << tmp << endl;
	}

	MyString(const MyString &tmp)
	{ // 拷贝构造函数
		len = tmp.len;
		str = new char[len + 1];
		strcpy(str, tmp.str);
		cout << "拷贝构造函数: tmp.str = " << tmp.str << endl;
	}

	MyString &operator=(const MyString &tmp)
	{ // 赋值运算符重载
		if (&tmp == this)
		{
			return *this;
		}

		// 先释放原来的内存
		len = 0;
		delete[] str;

		// 重新申请内存
		len = tmp.len;
		str = new char[len + 1];
		strcpy(str, tmp.str);

		cout << "赋值运算符重载: tmp.str = " << tmp.str << endl;

		return *this;
	}

	~MyString()
	{ // 析构函数
		cout << "析构函数 " << endl;
		if (nullptr != str)
		{
			cout << "已操作 delete str = " << str << endl;
			delete[] str;
			str = nullptr;
			len = 0;
			
		}
	}
private:
	char *str = nullptr;
	int len = 0;
};

MyString func() // 返回普通对象，不是引用
{
	MyString obj("mike"); // 1.普通构造函数

	cout << "&obj = " << (void *)&obj << endl;

	// 返回值优化技术 (不产生零时对象，obj直接过度给str)
	return obj; // 2.内存一临时区域，生成一个临时对象(新对象),由旧对象初始化新对象，调用拷贝构造函数
}
// g++ 37.my_string.cpp -fno-elide-constructors -std=c++11
// -fno-elide-constructors 关掉返回值优化
int main()
{
	MyString str = func(); // 3.func调用完毕，obj释放，调用析构函数

	cout << "&str = " << (void *)&str << endl;

	#if 0
	// 未优化
	// 构造 obj
	普通构造函数: tmp = mike
	&obj = 0x7ff7b36ac888

	// return 产生零时对象
	拷贝构造函数: tmp.str = mike
	析构函数 
	已操作 delete str = mike

	// 初始化str
	拷贝构造函数: tmp.str = mike
	析构函数 
	已操作 delete str = mike
	&str = 0x7ff7b36ac8e8
	析构函数 
	已操作 delete str = mike

	// 优化后
	// 不产生零时对象，obj直接过度给str
	普通构造函数: tmp = mike //obj初始化
	&obj = 0x7ff7bb89a888
	&str = 0x7ff7bb89a888
	析构函数 
	已操作 delete str = mike
	#endif

	return 0; // 4.str 释放，调用析构函数
}