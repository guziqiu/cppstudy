#include <iostream>
#include <cstdio>
#include <cstddef>
#include <cwchar>
using namespace std;

void func(int x) {
    cout << __PRETTY_FUNCTION__ << endl; // 输出函数具体形式
    cout << x << endl;
    return ;
}

void func(int *x) {
    cout << __PRETTY_FUNCTION__ << endl;
    cout << x << endl;
    return ;
}


int main() {


    //cout << NULL << endl;
    //cout << (nullptr) << endl;
    
    /*if (NULL) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
     if (nullptr) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

*/
    func(nullptr);

    //func(NULL); // call of overloaded 'func(NULL)' is ambiguous
    // NULL代表整数0，和空地址， 编译器不确定调用哪一个函数
    // nullptr ： 更加准确的空地址信息


    return 0;
}

