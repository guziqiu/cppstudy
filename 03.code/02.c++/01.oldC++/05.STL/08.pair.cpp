#include <iostream>
#include <string>
using namespace std;

// 对组 pair
void test() {
    

    // 构造方法
    pair<int, int> p(10, 20);
    cout << p.first << " " << p.second << endl;

    pair<int, string> p2 = make_pair(10, "guziqiu");
    cout << p2.first << " " << p2.second << endl;

    pair<int, string> p3 = p2;
}


int main() {
    test();

    return 0;
}
