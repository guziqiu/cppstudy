#include <iostream>
using namespace std;

void test1() { // 在编译期宏替换     
    const int i = 10;
    int *p = (int *)(&i);
    *p = 20;
    cout << "const i = " << i << ", *p = " << *p << endl; //这里编译器会直接将i替换为10
}

void test2() {  // 指向常量的指针 const int *a , *a 不变，a可以变

    int a = 10;
    int b = 20;
    
    const int *p = &a; // int const *a;
    cout << "const int *p = a = " << *p << endl;
    p = &b;
    // p = 12; // 指向常量的指针,指针指向的值不能变，指针存的地址可以改变
    cout << "const int *p = b = " << *p << endl;
}

void test3() { //常指针,指针不变,值可以变
    //int const *a;
    int a = 10;
    int b = 20;
    int *const p = &a;
    cout << " &a = " << &a << ", &b = " << &b << endl;
    cout << "int *const p = "  << *p << ", p = &a : " << p << endl;
    // p = &b;
    *p = b;
    cout << "int *const p = "  << *p << ", p = &b " << p << endl;

}

void test4() { // const int *const a;   //都不变，即（*a）不变，a也不变
    
}

// const可以修饰参数传递。
// 1.传递的值不可变
// 2.当 const 参数为指针时，可以防止指针被意外篡改。
// 值传递时，实参会被复制一份为形参，形参在函数体内不论如何改变都不会影响实参的值，
// 那么自然没必要加const了。只有当我们传递引用或指针时才需要考虑是否加const
//



int main() {
    test4();

    return 0;
}

