#include <iostream>
#include <memory>
using namespace std;

int main()
{
	shared_ptr<int> sp1(new int(11));
	shared_ptr<int> sp2 = sp1; // 拷贝构造，有两个对象和堆区空间绑定

	cout << "num = " << sp2.use_count() << endl; // 打印计数器

	// 释放sp1 只是计数器减一 堆区没有释放 释放sp1和堆区空间的绑定， 无法通过sp1操作堆区空间的内容
	sp1.reset();
	cout << "num1 = " << sp2.use_count() << endl; // 打印计数器
	cout << *sp2 << endl;
	if (nullptr == sp1)
	{
		cout << "sp1 is null" << endl;
	}

	// 释放sp2，只是计数器-1，当计数器的值为0，堆区空间就释放
	sp2.reset();
	cout << "num2 = " << sp2.use_count() << endl; // 打印计数器

	return 0;
}