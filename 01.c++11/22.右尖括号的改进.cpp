#include <iostream>
#include <vector>
using namespace std;

template<int i> class X {};
template<class T>
class Y {};

int main() {

	Y<X<10> > obj1; // c++11之前，两个右尖括号之间必须有空格
	Y<X<10>> obj2;

	return 0;
}
