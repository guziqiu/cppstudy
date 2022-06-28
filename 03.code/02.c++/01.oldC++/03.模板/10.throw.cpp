#include <iostream>
using namespace std;

class guziqiu : public exception {
public :
    guziqiu() = default;
    guziqiu& operator=(const guziqiu &) = default;

    const char* what() { // 解释异常
        return "I'm don't know what happened !";
    }


    ~guziqiu() = default;
};


void inner() {
    try {
        throw(guziqiu());
    } 
    catch(guziqiu &e) {
        cout << "inner exception caught first" << endl;
    }


    catch(guziqiu &e) {
        cout << e.what() << "inner exception caught second " << endl;
    }
}

void outer() {
    try {
        inner();
    } 
    catch(...) { // 捕获任意异常
        cout << "outer expection caught" << endl;
    }
}


int main() {
    int age = 100;

    outer();



    // cin >> age;
    try {
        if (age > 90) {
            cout << "before throw" << endl;
            throw(age);
            cout << "123" << endl;
        } else {
            cout << age << "---" << endl;
        }
    } 

    catch(int age) {
        cout << age << " is too big" << endl;
    }


    return 0;
}

