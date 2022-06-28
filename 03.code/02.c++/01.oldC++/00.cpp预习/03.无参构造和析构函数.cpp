#include <iostream>
#include <cstring>
using namespace std; 
  
class A {
public:
    A() {//无参构造函数
        m_a = 0;
        m_b = 0;
    }
    A(const A &another) {//拷贝构造
        cout << "A(const A&).." << endl;
    }
    #if 0
    A(const A &another) {//默认拷贝构造
        m_a = another.m_a;
        m_b = another.m_b;
    }
    #endif
    ~A() { //析构函数
        cout << "~A()..." << endl;
    }
private:
    int m_a;
    int m_b;
};
//  类中会有默认的无参构造函数：
// -->当没有任何 **显示的构造函数** （**显示的有参、显示的无参、显示的拷贝构造**）的时候，默认无参函数就会出现

// 会有默认的拷贝构造函数：
// -->当没有 **显示的拷贝构造函数** 时，默认的拷贝构造函数就会出现

// 会有默认的析构函数（垃圾回收）
// -->当没有    **显示的析构函数**  的时候，默认的析构函数就会出现

class Test {
public:
    Test() {
        cout << "Test()..." << endl;
        m_x = 0;
        m_y = 0;
    }
    Test(int x, int y) {
        cout << "Test(int x, int y)..." << endl;
        m_x = x;
        m_y = y;
    }
    Test(const Test & another) {
        cout << "Test(const Test & another)..." << endl;
        m_x = another.m_x;
        m_y = another.m_y;
    }
    void printT() {
        cout << "x = " << m_x << ", m_y = "  << m_y << endl;
    }
    void operator=(const Test &another) {
        cout << " operator=(const Test &another)..." << endl;
        m_x = another.m_x;
        m_y = another.m_y;
    }
    ~Test() {
        cout << "~Test()..." << endl;
    }
    
private:
    int m_x;
    int m_y;
};
// 析构函数调用的顺序， 跟构造函数相反， 谁先构造的， 谁先析构(栈)
void test1() {
    Test t1(10, 20);//调用有参构造
    Test t2(t1);// Test t2 = t1; 拷贝构造
    // 先析构t2，后析构t1

}
void test2() {
    Test t1(10, 20);;
    Test t2;
    t2 = t1;//  =  操作符
}
void func(Test t) {// Test t = t1;// Test t 的拷贝构造函数
    cout << "func begin .." << endl;
    t.printT();
    cout << "func end .." << endl;
}

void test3() {
    cout << "test3 begin .." << endl;
    Test t1(10, 20);
    func(t1);
    cout << "test3 end .." << endl;
}
int main() {
    test1();
    test2();
    

    return 0;
}