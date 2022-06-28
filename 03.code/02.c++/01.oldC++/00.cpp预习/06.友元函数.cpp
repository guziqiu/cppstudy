#include <iostream>
#include <cmath>
using namespace std; 


class PointManager {
public:
    double PointDistance(Point &p1, Point &p2);
};

class Point {
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int getX() {
        return this->x;
    }
    int getY() {
        return this->y;
    }
private:
    int x;
    int y;

// 声明全局函数PointDistance是类Point类的一个友元函数
//friend double PointDistance(Point &p1, Point &p2);
friend double PointManager::PointDistance(Point &p1, Point &p2);

};
#if 0
double PointDistance(Point &p1, Point &p2) {
    double dis;
    int ddx = p1.x - p2.x;
    int ddy = p1.y - p2.y;
    dis = sqrt(ddx * ddx + ddy * ddy);
    return dis;
}
#endif

double PointManager::PointDistance(Point &p1, Point &p2) {
        double dis;
        int ddx = p1.x - p2.x;
        int ddy = p1.y - p2.y;
        dis = sqrt(ddx * ddx + ddy * ddy);
        return dis;
}


int main() {
    Point p1(1, 2);
    Point p2(2, 4);
    //cout << PointDistance(p1, p2) << endl;
     
    PointManager pm;
    cout << pm.PointDistance(p1, p2) << endl;
    return 0;
}