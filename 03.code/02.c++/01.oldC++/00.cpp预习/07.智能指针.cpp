#include <iostream>
#include <memory>
using namespace std; 
  
class A{
public: 
    A(int a) {
        cout << "A()..." << endl;
        this->a = a;
    }
    void func() {
        cout << "a = " << this->a << endl;
    }
    ~A() {
        cout << "~A()..." << endl;
    }
private:
    int a;
};

void test1() {
    A *ap = new A(10);
    ap->func();
    (*ap).func();
    delete ap;
    cout << "-------" << endl;
    auto_ptr<A> ptr(new A(10));
    ptr->func();
    (*ptr).func();
}

class MyAutoPtr {
public :
    MyAutoPtr(A *ptr) {
        cout << "MyAutoPtr().." << endl;
        this->ptr = ptr;
    } 
    ~MyAutoPtr() {
        if (this->ptr != NULL) {
            cout << "~MyAutoPtr().." << endl;
            delete ptr;
            this->ptr = NULL;
        }
        A* operator->() {
            return this->ptr;
        }
    }
private :
    A *ptr;
};
void test2() {
    MyAutoPtr myPtr(new A(10));
    myPtr->func();
}

int main() {
    
    // auto_ptr<int> ptr(new int);// 智能指针
    // *ptr = 20;
    //不需要delete

    //  test1();
     cout << "-------" << endl;
     test2();


    return 0;
}