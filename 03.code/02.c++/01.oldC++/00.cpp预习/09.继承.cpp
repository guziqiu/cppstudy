#include <iostream>
using namespace std; 
// 家具类
class funiture {
public:
    int m;
    // void 
};
//将父亲类继承爷爷类，改成虚继承，防止儿子在多继承我的时候，出现爷爷的变量会拷贝多份
class bed :virtual public funiture{
public: 
    void sleep() {
        cout << "在床上睡觉" << endl;
    }
    // int m;
};

class sofa :virtual public funiture{
public: 
    void sit() {
        cout << "在沙发上上睡觉" << endl;
    }
};

// 沙发床  多继承
class sofabed :public bed, public sofa {
public:
    void sleepAndsit() {
        sleep();
        sit();
    }
};



int main() {
    bed b;
    b.sleep();
    sofa s;
    s.sit();
    cout << "--------" << endl;
    sofabed so;
    so.sleepAndsit();
    so.m = 100;//访问不明确，加virtual后访问明确,访问的是爷爷类的变量
    so.bed::m = 100;//
    so.sofa::m = 200;///


    

    return 0;
}