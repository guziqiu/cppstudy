#include <iostream>
#include <thread>
using namespace std;

void func(int x) {
    for (int i = 0; i < x; i++)   cout << i << endl;
    return ;
}

void add_one(int &x) {
    x += 1;
    return ;
}

int main() {
    
    int n = 8;
     //thread t1(func, 30);
    //thread t2(func, 30); // 同时输出两个数子说明是多线程
    thread t1(add_one, ref(n)); // 传引用需要加&
    t1.join();
    //t2.join();
    cout << "hello world" << endl;
    cout << n << endl; // 9

    return 0;
}

