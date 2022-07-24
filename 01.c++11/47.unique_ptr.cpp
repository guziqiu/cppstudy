#include <iostream>
#include <memory>
using namespace std;

class Test
{
public:
	~Test()
	{
		cout << "析构..." << endl;
	}
};

int main()
{
	unique_ptr<int> up(new int(11)); // 创建智能指针对象
	cout << "*up = " << *up << endl;
	// 重载 operator *()  有一个指针变量，指向堆区空间

	{
		unique_ptr<Test> up1(new Test()); //无需s释放，自动释放
	}
	cout << "-----" << endl;

	{
		unique_ptr<Test> up1(new Test()); //无需s释放，自动释放
		// up1 = nullptr; // 人为指定释放堆区空间
		// up1 = NULL;
		up1.reset();
		cout << "++++" << endl;
	}
	cout << "-----" << endl;

	unique_ptr<int> up1(new int(11)); // 创建智能指针对象，up1是唯一的使用者
	// unique_ptr<int> up2 = up1; // 禁用拷贝构造， err
	unique_ptr<int> up2 = std::move(up1); // ok up1的使用权转移给up2,up1就不能再操作堆区空间
	cout << *up2 << endl;
	if (nullptr == up1) cout << "up1 is null" << endl;

	{
		unique_ptr<int> up1(new int(11));
		// up1.reset(); // 如果是无参， 作用是显示释放堆区内容

		// 如果是有参数，先释放原来堆区内容，然后重新给up1绑定一个新的堆区内容
		up1.reset(new int(22));
		cout << *up1 << endl;
	}

	{
		unique_ptr<int> up1(new int(33));
		// 释放控制权，但是不释放堆区内存
		int *p = up1.release();
		if (nullptr == up1)
		{
			cout << "up1 is null" << endl;
		}
		cout << *p << endl;
		delete p;
	}

	return 0;
}