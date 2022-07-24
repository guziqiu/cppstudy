#include <iostream>
#include <thread>
using namespace std;
// 打印机
void printer(const char *str)
{
    while(*str != '\0')
    {
        cout << *str;
        str++;
        this_thread::sleep_for (chrono::seconds(1));
    }
    cout << endl;
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