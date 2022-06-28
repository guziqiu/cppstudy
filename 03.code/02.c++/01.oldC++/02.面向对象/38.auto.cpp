#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

class Base {
public :
    static int x; // 静态成员属性
    auto y;// 对象属性不能使用auto关键字来定义
};

auto Base::x = 123;


int main() {

    int x;
    auto y = 12.3; // c++ auto ： 
    int z = 123;
    // 根据变量自动定义类型，
    // 在c语言就有auto:
    // auto int z = 123; // C : 局部自动变量, 生存周期编译期自动决定，没有实际意义
    
    cout << typeid(x).name() << endl; // 返回类型信息对象，.name输出类型信息名字
    cout << typeid(y).name() << endl; // 返回类型信息对象，.name输出类型信息名字
    cout << typeid(z).name() << endl; // 返回类型信息对象，.name输出类型信息名字

    Base b;
    cout << typeid(b).name() << endl;

    if (typeid(y).hash_code() == typeid(float).hash_code()) {
        cout << "float type" << endl;
    }
    if (typeid(y).hash_code() == typeid(double).hash_code()) {
        cout << "double type" << endl;
    }










    return 0;
    cout << sizeof(x) << endl;
    cout << sizeof(y) << endl;

    map<int, int> arr;
    for (int i = 0; i < 10; i++) {
        arr[rand() % 100] = rand();
    }

    // C++ auto 应用场景
    // vector 容器 封装好的数据结构
    // 需求：遍历容器中的相关元素
    // 遍历工具：迭代器，每一种容器的迭代器类型不一样
    map<int, int>::iterator it = arr.begin();// map<int, int>的迭代器
    while (it != arr.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    cout << "++++++" << endl << endl;
    auto iter = arr.begin();// map<int, int>的迭代器
    while (iter != arr.end()) {
        cout << iter->first << " " << iter->second << endl;
        iter++;
    }

    cout << "++++++" << endl << endl;

    for (pair<int, int> i : arr) {
        cout << i.first << " " << i.second << endl;
    }

    cout << "++++++" << endl << endl;
    for (auto i : arr) {
        cout << i.first << " " << i.second << endl;
    }







    return 0;
}

