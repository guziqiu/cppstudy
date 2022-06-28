#include <iostream>
#include <cmath>
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

class Data {
public: 
    Data() {
        cout << this << " Data default constructor" << endl;
    }
    Data(const Data &a) {
        cout << this << " Data copy constructor" << endl;
    }
};

class A {
public:
    A() {
        cout << this << " A default constructor" << endl;
    }
    A(int x) : x(x) {
        cout << this << " A transform constructot" << endl;
    }
    A(const A &a) : x(a.x)/*, d(a.d)*/ {
        cout << this << " A copy constructor" << endl;
    }
    A &operator=(const A &a) {
        cout << this << " : A operator=" << endl;
        return *this;
    }
    int x;
    Data d;
private: 
};

A func() {
    A temp(69);
    cout << "func &temp: " << &temp << endl; 
    return temp;
}

int main() {
    A a = func(); // 
    cout << "main &a: " << &a << endl;  
    cout << a.x << endl;

    /*
    cout << "+++++++========+++++++" << endl;
    a = func();
    cout << a.x << endl;
*/

    return 0;
}
