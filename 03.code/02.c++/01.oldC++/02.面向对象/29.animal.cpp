#include <iostream>
using namespace std;

class A {
public :
    A() : x(123) {}
    int x;
};

class B : virtual public A { // 虚继承,子类会将虚继承的部分（来自同一个类）合并
public :
    void setX(int x) {
        //cout << "setX : &x = " << &(this->x) << endl;
        this->x = x;
        return ;
    }
};

class C : virtual public A {
public :
    int getX() {
        //cout << "getX : &x = " << &(this->x) << endl;
        return x;
    }
};

class D : public B, public C {
};

int main() {
    D d;
    cout << "&d" << &d << endl;
    cout << "get X :" << d.getX() << endl;
    d.setX(12345);
    cout << "get X :" << d.getX() << endl;


    return 0;
}

