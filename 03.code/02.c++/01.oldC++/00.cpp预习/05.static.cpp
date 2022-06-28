#include <iostream>
using namespace std; 



#if 0
class AA{
public:
    AA(int a, int b) {
        ma = a;
        mb = b;
    }
    //static修饰的静态成员变量
    static int mc;
    int getC() {
        mc++;
        return mc;
    }
    // 静态从成员方法
    static int& getCC() {
        return mc;
    }

private:
    int ma;
    int mb;
}; 
//static修饰的静态成员变量，静态区, 静态变量初始化一定写到类的外面
int AA:: mc = 100;
void test() {
    static int a = 10;
    a++;
    cout << a << endl;
}
static void test1() {
    // 该函数只能在本文件内使用
}

int main() {
    AA a1(10, 20);
    AA a2(100, 200);
    test();//11
    test();//12
    cout << "-------------" << endl;
    cout << a1.getC() << endl;//101
    cout << a2.getC() << endl;//102
    // 静态区对于整个类是共享的

    cout << "-------------" << endl;
    a1.mc = 100;
    AA::mc = 200;//mc属于这个类
    cout << a1.getC() << endl;//201
    cout << a2.getC() << endl;//202

    cout << "-------------" << endl;
    a1.getCC() = 300;
    AA::getCC() = 300;//mc属于这个类
    cout << a1.getC() << endl;//301
    cout << a2.getC() << endl;//302


    return 0;
}
#endif