#include <iostream>
using namespace std;

class Animal {
public :
    Animal(string name) : name(name) {}
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
private :
    string name;
};

class Cat : public Animal {
public :
    Cat(string name) : Animal(name) {}
    void run() override {
        cout << "I can run with four legs" << endl;
    }
};




int main() {
    Cat a("Tom");
    Animal &b = a;
    Animal *c = &a;
    
    a.run(); // 猫跑
    b.run(); // animal run
    c->run(); // animal run


    return 0;
}

