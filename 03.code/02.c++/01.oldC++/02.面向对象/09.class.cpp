#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

namespace haizei{
    class Cat {};

    class Dog {};

    class People {//默认访问权限是private，类内部
    public:
        string name;
        int age;
        double height;
        double weight;
        
        void say(string name);//声明
        #if 0
        void say() {//实现在内部
            cout << "my name is " << name << endl;
        }
        #endif
        void run();
    };

    void People::say(string name) {//实现在外部
        cout << "     this = " << this << endl;//this指针，只能在成员方法内部访问,发现this指针指向对象的地址
        cout << "my name is " << this->name << " " << name << endl;
        //this指针强调使用的成员属性,this->name成员属性，name指参数
    }
}// end of haizei

using namespace haizei;
int main() {
    haizei::People guziqiu;//写法1  ==> People::say People  是特殊的命名空间
    People apricity;//写法2，使用using namespace haizei; 不提倡

    guziqiu.name = "古子秋";//类外部,默认访问权限是private， 类外部不会访问，需要加上public
    apricity.name = "Apricity";

    cout << " &guziqiu = " << &guziqiu << endl;
    guziqiu.say("aha");
    cout << "&apricity = " << &apricity << endl;
    apricity.say("aha");

    haizei::Cat cat;
    
    return 0;
}

