#include <iostream>
using namespace std;

class Hellper {
public :
    Hellper() {
        cout << "constructor called" << endl;
    }
    ~Hellper() {
        cout << "deconstructor called" << endl;
    }
};

class myerror : public exception {
public :
    const char * what() { 
        return "expection myerror";
    } 
    string s;

};


void inner() {
    cout << "inner begin " << endl;
    try {
        Hellper h = Hellper();
        throw("123");
    }

    catch(...) {
        cout << "exception caught" << endl;
    }
    cout << "inner endl" << endl;

}

void outer() {
    try {
        cout << "outer begin" << endl;
        throw myerror();
        //inner();
    }
    catch(myerror& err) {
        err.s = "hello";
        cout << "outer exception caught err" << endl;
        cout << "&err.s" << &err.s << " : " << err.s << endl;
        throw;// 继续向上层抛出异常
    }
    cout << "outer endl" << endl;
}


int main() {
    try {
        outer();
    }
    catch(myerror& err) {
        
        cout << "catch err in main" << endl;
        cout << &err.s << endl;
        cout << err.s << endl;
    }

    return 0;
}

