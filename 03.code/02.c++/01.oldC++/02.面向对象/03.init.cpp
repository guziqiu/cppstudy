#include <iostream>
using namespace std;

class A{
public: 
    A() : x(123), y(234) {}//实际顺序=代码书写顺序
#if 0
    A() : y(x - 1), x(123) {//构造，  按顺序赋值，避免出现代码逻辑上的bug,
        //x = 123;//赋值
        //y = 0;
    }
#endif
    void say1() const {
        cout << "x = " << x << ", y = " << y << endl;
    }
    int x;
    int y;
};


int main() {
    A a;
    a.say1();
    

    return 0;
}

