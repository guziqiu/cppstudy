#include <iostream>
using namespace std;

class Uncopyable { // 只要基类不可以被拷贝，子类一定不能被拷贝
public :
    Uncopyable() = default;
    Uncopyable(const Uncopyable &) = delete;
    Uncopyable &operator=(const Uncopyable &) = delete;
};


class A : public Uncopyable {
public :
    //A(const A &) = delete; // 不允许被拷贝
};

class B : public Uncopyable {
public :
    //B(const B &) = delete;
};

class C : public Uncopyable {
public :
    //C(const B &) = delete;
};


int main() {
    A a;
    C c = a; //  conversion from 'A' to non-scalar type 'C' requested
    
    return 0;
}

