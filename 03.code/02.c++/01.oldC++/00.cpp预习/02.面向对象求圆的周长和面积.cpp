#include <iostream>
using namespace std;
// 面向过程
double getCircle(double r) {
    //得到圆的周长
    return 2 * 3.14 * r;
}

double getArea(double r) {//圆的面积
    return 3.14 * r * r;
}

// 面向对象
class Circle {
public :
    void setR(double r) {
        m_r = r;
    }
    double getR() {
        return m_r;
    }
    double getCircle() {
        //得到圆的周长
        return 2 * 3.14 * m_r;
    }

    double getArea() {//圆的面积
        return 3.14 * m_r * m_r;
    }

private:
    double m_r;//圆的私有成员 半径
};



int main () {

    double r = 10;
    double g = 0, a = 0;
    g = getCircle(r);
    a = getArea(r);
    cout << "圆的半径："  << r << endl;
    cout << "圆的周长："  << g << endl;
    cout << "圆的面积："  << a << endl;
    cout << "---------------------" << endl;
    Circle c;
    c.setR(r);
    cout << "圆的半径："  << c.getR() << endl;
    cout << "圆的周长："  << c.getCircle() << endl;
    cout << "圆的面积："  << c.getArea() << endl;

    return 0;
}