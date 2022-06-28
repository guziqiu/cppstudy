#include <iostream>
#include <functional>
#include <thread>
using namespace std;

void add_one(int &x) {
    cout << "add_one function " << endl;
    x += 1;
    return ;
}

class Task {
public :
    template<typename FUNCTION, typename ...ARGS>
    Task(FUNCTION &&f, ARGS ...args) {
        cout << "Task constructor" << endl;
        this->f = bind(f, forward<ARGS>(args)...); // 参数和变量的绑定
    }
    void run() {
        f();
    }
private :
    function<void()> f;

};


int main() {
     int n = 8;
     thread t1(add_one, ref(n));
     Task t2(add_one, ref(n));
     t1.join();
     t2.run();
     t2.run();
     t2.run();
     cout << n << endl;
    
    return 0;
}

