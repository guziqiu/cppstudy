#include <iostream>
using namespace std;

class A {
public :
    A() { x= 200; y = 400; }
    virtual void say(int x) {
        cout << "this->x : " << this->x << endl;
        cout << "class A say : " << x << endl;
    }
    virtual void run() {
        cout << "class A run" << endl;
    }
    void reg1() {
        cout << "reg1 function" << endl;
    }
    void reg2() {
        cout << "reg2 function" << endl;
    }
    void reg3() {
        cout << "reg3 function" << endl;
    }
    void reg4() {
        cout << "reg4 function" << endl;
    }
    void reg5() {
        cout << "reg5 function" << endl;
    }
    int x, y;
}; 

class B : public A {
public :
    B() { x = 300; }
    void say(int x) override {
        cout << "class B say : " << x << endl;
    }
};

class C : public A {
public :
    C() { x = 400; }
    void run() override {
        cout << "class C run" << endl;
    }
};


#define TEST(a) test(a, #a)
void test(A &a, string class_name) {
    cout << "Object " << class_name << endl;
    a.say(123);
    a.run();
    cout << "=========" << endl << endl;
    return ;
}

typedef void (*func)(void *,int);



int main() {
    
    A a;
    B b;
    C c;
    TEST(a); // A say A run  
    TEST(b); // B say A run
    TEST(c); // A say C run
    ((void **)(&b))[0] = ((void **)(&c))[0]; // 将b的虚函数指针指向c的虚函数表 // A say C run 
    TEST(b);

    ((func **)(&b))[0][0](&b, 100); // b函数指向c的say(A say)方法 // A say (this->x : 300)
    // &b this指针， this指针是成员方法隐藏的参数
    // 为什么是300
    // 传入的&b即传入的是b对象的this指针的地址，所以值的b的this指针的值
    cout << "=========" << endl << endl;
    ((func **)(&b))[0][0](&c, 100);  // this->x = 400
    // ==> 
    //
    
    // 成员方法指针
    void (A::*p)(int);
    p = &A::say;
    (a.*p)(12345);


    void (A::*q[3])(); // 成员方法指针

   

    q[0] = &A::reg1;
    q[1] = &A::reg2;
    q[2] = &A::reg3;
    for (int i = 0; i < 10; i++) {
        (a.*q[rand() % 3])();
    }


    cout << "=++++ a.x" << endl;
    int A::*d; // 成员属性指针
    d = &A::x;
    cout << (a.*d) << endl; // a.x
    cout << a.x << endl;
    
    cout << " a.y" << endl;
    d = &A::y;
    cout << (a.*d) << endl; // a.x
    cout << a.y << endl;
    cout << " +++++" << endl;






    return 0;
}

