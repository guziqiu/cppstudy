#include <iostream>
using namespace std;

class Animal {
public :
    Animal(string name = "加菲猫") : name(name) {
        cout << "Animal default constructor" << endl;
    }
    Animal(const Animal &a) : name(a.name) {
        cout << "Animal copy constructor" << endl;
    }
    Animal &operator=(const Animal &a) {
        this->name = a.name;
        return *this;
    }
    void say() {
        cout << "my name is " << name << endl;
        name2 = "加菲猫";
    }
    void rename(string name) {
        this->name = name;
        return ;
    }
    ~Animal() {
        cout << "Animel destructor" << endl;
    }
protected :
    string name;
protected :
    string name2;
};

class Cat : public Animal { 
public :
    Cat() : Animal("Cat MIMI") {
        cout << "Cat default structor" << endl;
    }
    Cat(const Cat &c) : Animal(c) { // 在子类中显示的调用父类的构造函数
        cout << "Cat copy constructor" << endl;
    }
    Cat &operator=(const Cat &c) {
        this->Animal::operator=(c);
        return *this;
    }
    void say1() {
        cout << "加菲猫, my name is " << name << endl; // std::string Animal::name' is private within this context
        //cout << "加菲猫, my name is " << name2 << endl; // 子类可以访问父类的pritected
    }
    ~Cat() {
        cout << "Cat deconstructor" << endl;
    }
};

class Tigger : public Cat {
public :
    void say2() {
        // cout << "houhouhou, my name is " << name2 << endl; // 无法访问private继承 private Animal
        // 可以访问protected继承，和public继承
        //
    }
};

int main() {
    //cout << sizeof(Animal) << " " << sizeof(Cat) << endl; // 32 32 ==> Cat 继承了 Animal 的内容， 大小一样
    Cat c;
    Cat a = c; // c拷贝给a
    cout << "a.say1()" << endl;
    a.say1();
    //c.say(); // Cat继承了Animal的内容 public Animal
    cout << "c.say1()" << endl;
    c.say1();

    //Animal *p = &c; // 通过父类的指针访问子类继承父类的内容，前提条件是继承方法必须是public继承, 如果Cat是private和protected继承，则无法访问
    //p->say();
    
    
    return 0;
}

