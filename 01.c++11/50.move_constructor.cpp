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
private:
	char *str = nullptr;
	int len = 0;
};

MyString func() 
{
	MyString obj("mike"); 

	cout << "&obj = " << (void *)&obj << endl;

	
	return obj; 
}

// g++ 50.move_constructor.cpp -fno-elide-constructors -std=c++11
// 普通构造函数: tmp = mike
// &obj = 0x7ff7bc091888
// 移动构造函数。。。
// 析构函数 
// &str = 0x7ff7bc0918e0
// 析构函数 
// 已操作 delete str = mike


int main()
{
	MyString &&str = func();  //右值引用

	cout << "&str = " << (void *)&str << endl;

	return 0; 
}