#include <iostream>
#include <thread>
using namespace std;
mutex g_lock; //全局互斥锁对象，#include <mutex>

// 打印机
void printer(const char *str)
{
    g_lock.lock(); //上锁
    while(*str != '\0')
    {
        cout << *str;
        str++;
        this_thread::sleep_for (chrono::seconds(1));
    }
    cout << endl;

    g_lock.unlock(); //解锁
}

// 线程一
void func1()
{
	const char *str = "hello";
	printer(str);
}

// 线程二
void func2()
{
    const char *str = "world";
    printer(str);
}

int main(void)
{
    thread t1(func1);
    thread t2(func2);

    t1.join();
    t2.join();

    return 0;
}