#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class People {
public:
    People() : say_cnt(0) {
        People::total_num += 1;
    }
    static void say_count() {
        cout << People::total_num << endl;
    }
    void say() const { // const类型必须调用const类型方法
        cout << "hahahah~, funny!" <<endl;
        output();  // const output
        say_cnt += 1; // 逻辑意义上的const
        return ;
    }
    void output() {
        cout << "non-const output function" << endl;
    }
    void output() const { // 函数重载 
        cout << "const output function" << endl;
    }

    ~People() {
        People::total_num -= 1;
    }
private:
    mutable int say_cnt; // mutable 实现逻辑意义上的const
    static int total_num; // 声明，在类内加static，为了和其他变量区分

};

int People::total_num = 0; // 类的变量的定义， 不需要加static关键字


int main() {
    People a, b;
    a.say_count();
    People::say_count();

    {
        People a, b;
        People::say_count();
    }
    People::say_count();
    
    const People c;
    c.say(); // const 类型对象不能调用非const类型的方法，因为可能会改变const类型的变量
    
    return 0;
}

