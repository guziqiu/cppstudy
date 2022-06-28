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
auto add(T a, U b) -> decltype(a + b){ // decltype 类型锈化 调用了T的默认构造函数
    return a + b;
}

auto func(int a, int b) -> int { // 返回值后置
    return a + b;
}

int main() {
    A a(3), b(5);
    cout << (a + b) << endl;
    cout << add(a, b) << endl;
    
    cout << add(1, 2) << endl;
    cout << add(1.2 ,2.2) << endl;
    cout << add<double>(1 ,2.2) << endl; // 强制将int转换成double
    cout << add(1 ,2.2) << endl;  // 改写模板
        
    decltype(1 + 2) x; // 根据(1 + 2)类型推导出 x 的类型 
    if (typeid(x).hash_code() == typeid(int).hash_code()) cout << "int" << endl;

    cout << "+++++++++++++" << endl;
    
    return 0;
}

