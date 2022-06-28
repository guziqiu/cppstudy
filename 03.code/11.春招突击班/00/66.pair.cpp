#include <iostream>
 
#include <map>
 
using namespace std;

int main() {
    map<char, int> m;
    m.insert(make_pair('a', 90));
    m['b'] = 88;

    if (m.count('a') == 1) {
        cout << m['a'] << endl;
    }// 90

    if (m.count('b') == 1) {
        cout << m['b'] << endl;
    } // 88

    if (m.count('c') == 1) {
        cout << m['c'] << endl;
    } else {
        cout << "NO" << endl;
    }// NO

    if (m['a']) cout << m['a'] << endl;// 90

    cout << m['c'] << endl; // 0 访问没有元素会输出0
    cout << m.count('c') << endl; // 没有的元素会自动添加，默认值0

    return 0;
}
