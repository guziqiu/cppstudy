#include <iostream>
using namespace std;


// func(int)
// func(int, int)
int func(int x, int y = 2) {
    return x * y;
}

//double func(int x) {//无法通过返回值区分函数类型
//    return x * x + 5;
//}


// 
double func(double x) {
    return x * x;
}

int main() {

    cout << func(2) << endl;; // func() 1
    cout << func(5.3) << endl; // func()2
    cout << func(2, 4) << endl; // func() 3

    return 0;
}

