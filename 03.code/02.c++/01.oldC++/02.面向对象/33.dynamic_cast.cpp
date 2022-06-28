#include <iostream>
using namespace std;

class A {
public :
    A() {
        cout << "A constructor" << endl;
    }
    //virtual void say() {
    //    cout << "Class A" << endl;
    //}
    virtual ~A() {
        cout << "A deconstructor" << endl;
    }
};

class B : public A{
public :
    B() {
        cout << "B constructor" << endl;
    }

    //void say() override {
    //    cout << "Class B" << endl;
    //}
    virtual ~B() {
        cout << "B deconstructor" << endl;
    }

};

class C : public A{
public :
    C() {
        cout << "C constructor" << endl;
    }

    //void say() override {
    //    cout << "Class C" << endl;
    //}
    virtual ~C() {
        cout << "C deconstructor" << endl;
    }

};

int main() {
    srand(time(0));
    A *p;

    switch (rand() % 2) {
        case 0:
            p = new B(); break;
        case 1:
            p = new C(); break;
    }
    delete p; // p是A类，是普通的成员方法，只会析构A的成员方法，
    // 这时一定要将析构函数设计成虚构
    // p -> B ? C ?
    //cout << dynamic_cast<B *>(p) << endl; // dynamic_cast 将p地址尝试转换成目标地址B
    //cout << dynamic_cast<C *>(p) << endl; // 如果不成功返回0




    return 0;
}

