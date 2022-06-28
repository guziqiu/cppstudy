#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T, typename ...ARGS>
struct N_ARGS {   // 解析变参列表小工具
    typedef T type;
    typedef N_ARGS<ARGS...> rest;
};

template<typename T> // 偏特化版
struct N_ARGS<T> {
    typedef T type;
    typedef T last; // 控制变参列表的最后一个参数，不是最后一个会报错
};


// 获取指定的第n个参数
template<int N, typename T, typename ...ARGS>
struct NewN_ARGS {   // 解析变参列表小工具
    typedef typename NewN_ARGS<N - 1, ARGS...>::type type;
    static int last() { // 是最后一个参数返回1
        return NewN_ARGS<N - 1, ARGS...>::last();
    }
};

template<typename T, typename ...ARGS> // 偏特化版
struct NewN_ARGS<1, T, ARGS...> {
    typedef T type;
    static int last() { return 0; }
};

template<typename T> // 偏特化版
struct NewN_ARGS<1, T> {
    typedef T type;
    static int last() { return 1; }
};


template<typename T>
void print(T a) { // 让递归终止在偏特化版本
    cout << a << endl;
    return ;
}

template<typename T, typename ...ARGS>
void print(T a, ARGS... args) { // 打印任意参数
    cout << a << endl;
    cout << a << " next type : " << typeid(typename N_ARGS<ARGS...>::type).name() << endl;
    print(args...); // 每一次递归减少一个参数
//    N_ARGS<ARGS...>::type;// 第一个变量名称
//    N_ARGS<ARGS...>::rest; // 剩余变量名称
    return ;
}

#define Test(func...) cout << #func << " = " << func << endl

int main() {
    print(123, 34.6);
    print(123, "hello world", "haizei", 45.6);


    N_ARGS<int, int, double, double>::type x;
    N_ARGS<int, int, double, double>::rest::type y;
    N_ARGS<int, int, double, double>::rest::rest::type z;
    N_ARGS<int, int, double, double>::rest::rest::rest::last w;

    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << typeid(z).name() << endl;
    cout << typeid(w).name() << endl;


    NewN_ARGS<1, int, int, double, double>::type x1;
    NewN_ARGS<2, int, int, double, double>::type x2;
    NewN_ARGS<3, int, int, double, double>::type x3;
    NewN_ARGS<4, int, int, double, double>::type x4;
    

    Test(NewN_ARGS<1, int, int, double, double>::last());
    Test(NewN_ARGS<2, int, int, double, double>::last());
    Test(NewN_ARGS<3, int, int, double, double>::last());
    Test(NewN_ARGS<4, int, int, double, double>::last());
    


    return 0;
}

