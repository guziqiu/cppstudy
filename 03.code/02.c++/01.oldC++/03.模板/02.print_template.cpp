#include <iostream>
using namespace std;

template<typename T> // 模板类
class PRINT { // 可以打印任意类型的元素
public :
    PRINT &operator()(T a) {
        cout << a << endl;
        return *this;
    }
};

class PRINT2 { // 可以打印任意类型的元素
public :
    template<typename T> // 模板成员方法
    PRINT2 &operator()(T a) {
        cout << a << endl;
        return *this;
    }
};

int main() {
    PRINT<int> print_int;
    print_int(123);
    print_int(3455);
    PRINT<string> print_str;
    print_str("hello guziqiu");
    print_str("hello haizei");

    // 打印任意类型
    PRINT2 print;
    print(123)("hello guziqiu")(4456);



    return 0;
}

