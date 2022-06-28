#include <iostream>
using namespace std;

class Animal {
public :
    Animal(string name) : name(name) {}
    virtual void run() = 0; // 纯虚函数 作用: 规定子类中必须实现的方法
    virtual void getName() final {} // 应用场景1：不想被子类修改的内容
    virtual void fl1() {}
private :
    string name;
};

class Cat : public Animal {
public :
    Cat(string name) : Animal(name) {}
    void run() override final {
        cout << "I can run with four legs" << endl;
    }
    //void fll() {} // 想重写fl1(),实际上函数名字打错了，但是编译器不会报错
    //void fll() override {} // 但是如果加上override就会报错, 提示函数不存在，主要起提示作用，完成语义的严谨性,减少bug
};

class Tigger : public Cat {
public :
    //void run() {} // 子类无法重载父类的final, final终结虚函数
    // final禁止重写
};



class People : public Animal {
public :
    People(string name) : Animal(name) {}
    void run() {
        cout << "I can run with two legs!" << endl;
    }
};

class Bat : public Animal {
public :
    Bat(string name) : Animal(name) {}
    void run() {
        cout << "I can fly!" << endl;
    }
};

class House : public Animal {
public :
    House() : Animal("House") {}
    void run() override {
        cout << "house, I can run wirh four legs!" << endl;
    }
};


int main() {
    cout << "Hello world!" << endl;
    House h;

    return 0;
}

