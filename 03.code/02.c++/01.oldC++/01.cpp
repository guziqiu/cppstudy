#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class A {
public :
    A() {
        cout << "A " << endl;
    }
};
class B : public A{
public : 
    B() {
        cout << "B" << endl;
    }
};

int main() {
    B b;

    return 0;
}
