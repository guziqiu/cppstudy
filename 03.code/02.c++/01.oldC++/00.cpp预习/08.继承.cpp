#include <iostream>
#include <cstring>
using namespace std; 
// 规则1：只要是父类的private成员，不管是说明继承方式，儿子都访问不了
// 规则2：如果是public继承，儿子中的访问控制权限保持不变
// 规则3：如果是protected继承，儿子中父亲除了private，其余在儿子中都是protected
// 规则4： 如果是private继承，儿子中的父亲除了private成员，其余在儿子中都是private成员
class Parent {
public:
    int pub;// 在类的内部 和 外部都能访问
protected: 
    int pro;// 在类的内部可以访问，在类的外部不可以访问
private:
    int pri;// 在类的内部可以访问，在类的外部不可以访问
};
// 公有继承
class Child :public Parent{
public:
    void func() {
        cout << pub << endl; // pub 父类的public成员变量，在public继承类的 内部和外部 可以访问,
        cout << pro << endl; // pro 是父类protected成员变量， 在public继承类的 内部 可以访问，外部不可以访问；
                            // 但是在孙子可以访问，说明pro不是private成员，是protected成员
        // cout << pri << endl; // pri 是父类private成员变量， 在public继承类的 内部和外部 不可以访问
    }
}; 

// 孙子类
class SubChild :public Child {
    void subfunc() {
    cout << "subschild : " << pro << endl;
    }
};

// 保护继承
class Child2 : protected Parent {
public:
    void func2() {
        cout << pub << endl;// 通过保护继承可以在类的内部访问
                            // pub在类的内部可以访问，在类的外部不可以访问，类的儿子可以访问
                            // pub是protected
        cout << pro << endl;// pro和pub是一样的性质，pro也是protected成员
        // pri; // 
    }
};
class Subchild2:public Child2 {
public:
    void sunfunc2() {
        cout << pub << endl;
        cout << pro << endl;
    }
private:
};
// 私有继承
class Child3 :private Parent {
public:
    void func3() {
        cout << pub << endl;
        //pub在类的内部可以访问,在类的内部可以访问，在类的外部不可以访问
        // 在儿子中访问不了，说明pub在child3中是私有成员
        pro;//和pub性质一样，
        //pri;//
    }
};

class subChild3 :public Child3 {
public:
    void subfunc3() {
        //cout << pub << endl;//
    }
};

int main () {
    Child c1;
    c1.pub = 10;
    c1.func();
    // c1.pro;
    // c1.pri;
    Child2 c2;
    // c2.pub;
    // c2.pro;
    Child3 c3;
    // c3.pub;
    // c3.pro;

    
    return 0;
}









#if 0

class Student {
public:
    Student(int id, string name) {
        this->id = id;
        this->name = name;
    }
    void printS() {
        cout << "id = " << this->id << ", name = " << this->name << endl;
    }
private:
    int id;
    string name;
};

// 创建一个新的学生类，增加score功能
class Student2 {// 类B继承类A,耦合度高
public:
    Student2(int id, string name, int score) {
        this->id = id;
        this->name = name;
        this->score = score;
    }
    void printS() {
        cout << "id = " << this->id << ", name = " << this->name << endl;
        cout << "score = " << this->score << endl;
    }
private:
    int id;
    string name;
    // add
    int score;
};

// 继承
class student3 :public Student {
public:
    student3(int id, string name, int score) :Student(id, name) {
        this->score = score;
    }
    void printS() {
        Student::printS();
        cout << "score = " << this->score << endl;
    }
private:
    int score;
};

int main() {

    student3 s3(1, "zhangsan", 88);
    s3.printS();
    

    return 0;
}

#endif
