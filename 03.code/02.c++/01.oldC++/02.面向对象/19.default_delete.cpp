#include <iostream>
using namespace std;

class A {
public:
    //A() = delete; // 删除默认构造函数
    //A(const A &) = default; // 使用默认拷贝构造   没有任何功能上的意义， 可以尽量避免发生错误
    A() = default;
    A &operator=(int x) {
        this->x = x;
        return *this;
    }
    int x;
private:
    A(const A &) = delete;
    A &operator=(A &a);
    const A &operator=(const A &a) const;
};



int main() {
    A a;
    A b;
    //a = b;
    (a = 123) = 456;
    cout << a.x << endl;

    return 0;
}

