#include <iostream>
using namespace std;

class Data { // 数据类
public:  
    Data() {}
    // Data(int x, int y) {// 没有默认构造，当添加了有参构造的时候，编译器默认添加的无参构造就会被删除，
    //     this->x = x;
    //     this->y = y;
    // }
    Data(int x, int y) : x(x), y(y) {
        cout << this << endl;
    }// 在构造列表初始化，保证在大括号之内已经构造完对象

    friend ostream &operator<<(ostream &out, const Data &d);
private:
    int x, y;
};



class A {
public:
    Data c, d;
    A() : c(d), d(3, 4) {// :d(3, 4) 初始化列表，初始化对象的每一个属性，初始化列表执行完后，对象已经构造完了
       
        cout << this << " constructor()" << endl;
        cout << " c : " << &c << endl;
        cout << " d : " << &d << endl;
    }
    A(int x) : d(x, x), c(3, 4) {// 转换构造
        cout << this << " : transform constructor" << endl;
    }
    // A(A a1) {}
    A(const A &a) : d(a.d) { // 避免传过来的变量是一个临时变量,同时也可以处理传过来的参数是const类型
        cout << this << " : copy constructor" << endl;;
    }



    const A &operator=(const A &a) const {
        cout << this << " : operator=" << endl;
        return *this;
    }

    ~A() {//析构函数在main函数执行完后调用
        cout << this <<" ~destructor()" << endl;
    }

private:

};

void add_one(int x) {
    x += 1;
    return ;
} 
void add_one1(int &x) {// 传引用不产生拷贝行为
    x += 1;
    return ;
} 

ostream &operator<<(ostream &out, const Data &d) {
    out << "(" << d.x << " " << d.y << ")" << endl;
}

int main() {

    Data d(10, 9);
    cout << d << endl;

    return 0;



    const A a;
    A b = a;
    A c = 3;
    



#if 0



    return 0;
    // int n = 3;
    // add_one(n);
    // cout << n << endl;
    // add_one1(n);
    // cout << n << endl;
    // return 0;

    A a;
    A b = a;// 定义行：此处不论是写A b = a;或者A b(a); 都会调用拷贝构造
    //b = a;// 调用复制运算符
    // 调用b对象的拷贝构造， b对象的拷贝构造需要传一个参数a1, 也就是 a1 = a,这个过程会调用a1的拷贝构造A(A a1) {}
    // a1的拷贝构造调用a1的拷贝构造，造成死循环，
    // 拷贝构造不能用值传递
    // 传引用不产生拷贝行为

    








    //return 0;

    // A c(3);
    // A d = 4;// 转换构造， 一般相同类型的才能赋值，赋值给一个对象，说明把这个值转换成了一个A类型，也就是转换构造
        
    // a = 3;// 转换成零时匿名对象 x(调用转换构造),然后绑定到a,最后this指向main函数中的a


    // 先定义先构造，构造的时候B对象可能依赖A对象的信息， 先定义后析构，B析构的时候可能依赖于A对象的信息
    cout << "a : " << &a << endl;
    cout << "b : " << &b << endl;
    // cout << "c : " << &c << endl;
    // cout << "d : " << &d << endl;
    cout << "end of main" << endl;
    return 0;
#endif 
}

