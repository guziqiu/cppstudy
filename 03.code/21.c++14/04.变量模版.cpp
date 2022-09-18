#include <iostream>
using namespace std;

template<class T>
constexpr T pi = T(3.1415926535897932385L);

template<typename T, typename U>
struct A {
   T t;
   U u;
};

template<typename T>
using B = A<T, int>;

int main() {

	cout << pi<int> << endl; // 3
	cout << pi<double> << endl; // 3.14159


	B<double> b;
	b.t = 10;
	b.u = 20;
	cout << b.t << endl;
	cout << b.u << endl;

	return 0;
}
