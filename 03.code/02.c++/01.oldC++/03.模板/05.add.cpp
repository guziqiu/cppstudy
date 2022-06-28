#include <iostream>
using namespace std;

class A {
public :
    A() = delete;
    A(int x) : x(x) {}
    A operator+(const A &a) {
        return A(x + a.x);
    }
    friend ostream &operator<<(ostream &, const A &);
private :
    int x;
};

ostream &operator<<(ostream &out, const A &a) {
    out << a.x << endl;
    return out;
}

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b){ 
    return a + b;
}


template<typename T, typename U>   // 模板偏特化，传入的是指针类型的变量
auto add(T *a, U *b) -> decltype(*a + *b){ // decltype 类型锈化 调用了T的默认构造函数
    return *a + *b;
}
template<typename T, typename U>   // 模板偏特化，传入的是指针类型的变量
auto add(T **a, U **b) -> decltype(**a + **b){ // 解指针
    return add(*a, *b);
}


template<>  // 模板的特化，特殊处理 
int add(int a, int b) {
    return a + b * 2;
}


auto func(int a, int b) -> int { 
    return a + b;
}

int main() {
    cout << "+++++++++++++" << endl;
    int n = 123, m = 456;
    int *p = &n, *q = &m;
    int **pp = &p, **qq = &q;
    
    cout << add(p, q) << endl; // 模板偏特化 传指针，
    cout << "++++" << endl;
    //cout << add(pp, qq) << endl; // 模板偏特化 传指针，

    cout << add(1, 2) << endl; // 调用的是特化版本


    return 0;
}

