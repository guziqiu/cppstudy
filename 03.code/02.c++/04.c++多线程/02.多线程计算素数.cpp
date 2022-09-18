#include <iostream>
#include <thread>
#include <string>
using namespace std;

#define BEGIN(x) namespace x{
#define END(x) }

int cnt = 0;
void func()
{
	cout << this_thread::get_id() << ":begin" << endl;
	for (int i = 0; i < 10000; ++i)
	{
		int tmp = cnt;
		tmp++;
		cnt = tmp;
		// cout << __PRETTY_FUNCTION__ << endl;
	}
	cout << this_thread::get_id() << ":end" << endl;
}

void func1(int x, string msg)
{
	cout << x << ":" << msg << endl;
}

int main()
{
	// thread t1(func);
	// thread t2(func);
	// thread t3(func);
	// thread t4(func);
	// thread t5(func);

	// t1.join();
	// t2.join();
	// t3.join();
	// t4.join();
	// t5.join();

	// cout << __PRETTY_FUNCTION__ << endl;
	// cout << "cnt = " << cnt << endl;
	thread t1(func1, 3, "hello");
	t1.join();

	return 0;
}