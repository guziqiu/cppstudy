#include <iostream>
using namespace std;

class Point {
public : 
    Point();
    Point(int x, int y);
    Point operator+(const Point &);  // 类内重载
    Point &operator+=(int);  // 类内重载
    int operator[](string s);
    int getX() { return x; }
    int getY() { return y; }
private :
    friend Point operator+(const Point &a, const Point &b);
    friend ostream &operator<<(ostream &out, const Point &a);
    int x;
    int y;
};
class PPoint { // 指向Point的指针
public :
    PPoint(Point *p) : p(p) {}
    Point *operator->() {
        return p;
    }
private :
   Point *p;
};

class ADD {
public :
    ADD(int c) : c(c){}
    int operator()(int a, int b) {
        return a + b + c;
    }
private :
    int c;
};





Point::Point() : x(0), y(0) {}
Point::Point(int x, int y) : x(x), y(y) {}

int Point::operator[](string s) {
    if (s == "x") return x;
    if (s == "y") return y;
    return 0;
}

//string operator()(string s) {
//    return s;
//}



Point Point::operator+(const Point &a) { // 类内重载
    cout << "inner operator+" << endl;
    Point c(this->x + a.x, this->y + a.y);
    return c;
}

Point &Point::operator+=(int n) {  // 类内重载
    x += n, y += n;
    return *this;
}


Point operator+(const Point &a, const Point &b) { // 类内重载
    cout << "outer operator" << endl;
    Point c(a.x + b.x, a.y + b.y);
    return c;
}

ostream &operator<<(ostream &out, const Point &a) {
    out << "(" << a.x << "," << a.y << ")" << endl;
    return out;
}

int main() {


    ADD add(5);
    cout << add(6, 7) << endl;



    Point a(3, 4);
    Point b(7, 9);
    Point c = a + b;



    cout << a["x"] << endl;
    cout << a["y"] << endl;
    //return 0;


    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    a += 2;
    cout << a << endl;
        
    PPoint p = &a;
    cout << p->getX() << " " << p->getY() << endl;

    return 0;
}

