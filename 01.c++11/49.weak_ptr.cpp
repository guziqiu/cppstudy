#include <iostream>
#include <memory>
using namespace std;

int main()
{
	shared_ptr<int> p1(new int(11));
	shared_ptr<int> p2 = p1; // 有2个指针变量绑定堆区内容

	weak_ptr<int> wp = p1; //  有2个指针变量绑定堆区内容

	cout << "num1 = " << p1.use_count() << endl;
	cout << "num2 = " << p2.use_count() << endl;
	cout << "num wp = " << wp.use_count() << endl;
	cout << "-----" << endl;

	// weak_ptr 虽然不和堆区空间绑定，但是可以通过lock函数获取shared_ptr<int>对象
	shared_ptr<int> p3 = wp.lock(); // 有3个指针变量绑定堆区内容

	cout << "num1 = " << p1.use_count() << endl;
	cout << "num2 = " << p2.use_count() << endl;
	cout << "num wp = " << wp.use_count() << endl;
	cout << "num3 = " << p3.use_count() << endl;

	cout << *p1 << ", " << *p2 << "," << *p3 << endl;
	// cout << *wp << endl; // err 没有重载 * 和 ->
	cout << "-----" << endl;

	p1.reset();
	p2.reset();
	p3.reset();
	cout << "num1 = " << p1.use_count() << endl;
	cout << "num2 = " << p2.use_count() << endl;
	cout << "num wp = " << wp.use_count() << endl;
	cout << "num3 = " << p3.use_count() << endl;
	cout << "-----" << endl;

	// 堆区空间已经释放后，wp.lock()获取的返回值为空
	shared_ptr<int> tmp = wp.lock();
	if (nullptr == tmp)
	{
		cout << "堆区空间已经释放。。。" << endl;
	}


	return 0;
}