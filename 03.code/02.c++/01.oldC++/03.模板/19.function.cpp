#include <iostream>
#include <functional>
using namespace std;

namespace guziqiu {

template<typename T, typename ...ARGS>
class base {
public :
    virtual T run(ARGS...) = 0;
    virtual base<T, ARGS...> *getCopy() = 0;
    virtual ~base() {}
};

template<typename T, typename ...ARGS>
class normal_func : public base<T, ARGS...> {// base 派生类
public :
    typedef T (*FUNC_T)(ARGS...);
    normal_func(FUNC_T func) : func(func) {}
    T run(ARGS ...args) override {
        return func(forward<ARGS>(args)...);
    }
    base<T, ARGS...> *getCopy() override {
        return new normal_func(func);
    }

private:
    FUNC_T func;
};

template<typename C, typename T, typename ...ARGS>
class functor : public base<T, ARGS...>{// base 派生类
public :
    functor(C obj) : obj(obj) {}
    T run(ARGS ...args) override {
        return obj(forward<ARGS>(args)...);
    }
    base<T, ARGS...> *getCopy() override {
        return new functor(obj);
    }

private : 
    C obj;
};


template<typename T, typename ...ARGS> class function;
template <typename T, typename ...ARGS> // 模板类的偏特化版本
class function<T(ARGS...)> {
public :
    function(T (*ptr)(ARGS...)) : fptr(new normal_func<T, ARGS...>(ptr)) {} // 兼容普通指针类型
    template<typename C>
    function(C object) : fptr(new functor<C, T, ARGS...>(object)) {}

    function(const function &obj) {
        cout << "copy constructor" << endl;
        this->fptr = obj.fptr->getCopy();// 深拷贝
    } // 拷贝构造

    function(function<T(ARGS...)> &&obj) : fptr(obj.fptr){
        this->fptr = obj.fptr;
    } // 移动构造
    
    function &operator=(function &obj) { // 左值赋值运算符
        if (this == &obj) return *this;
        if (this->fptr) delete this->fptr;
        this->fptr = obj.fptr->getCopy();
        return *this;
    }
    function &operator=(function &&obj) { // 右值赋值运算符
        if (this == &obj) return *this;
        this->fptr = obj.fptr;
        obj.fptr = nullptr;
        return *this;
    }
    
    T operator()(ARGS ...args) {
        return fptr->run(forward<ARGS>(args)...);
    }
    ~function() {
        if (fptr != nullptr) delete fptr;
        fptr = nullptr;
    }
private :
    base<T, ARGS...> *fptr;
};

} // end of guziqiu 

void func(int a, int b) {
    cout << "normal function" << endl;
    return ;
}

class ADD_FUNC {
public :
    ADD_FUNC() : x(0) {}
    void operator()(int a, int b) {
        x += a + b;
        cout << "class object : " << x << endl;
        return ;
    }
    int x;
};

int main() {
    ADD_FUNC add;
    function<void(int, int)> F1 = func;
    function<void(int, int)> F2 = add;
    F1(3, 4);
    F2(3, 4);
    F2(5, 6);

    guziqiu::function<void(int, int)> f1 = func;
    guziqiu::function<void(int, int)> f2 = add;
    f1(3, 4);
    f2(3, 4);
    f2(5, 6);

    guziqiu::function<void(int, int)> f3(f2);
    f3(7, 8);
    f3 = f1;
    f3(7, 8);
    
    return 0;
}

