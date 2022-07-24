#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

void example() {
	int i ;
	decltype(i) j = 0;
	cout << "is int:";
	cout << ( typeid(int).name() == typeid(i).name() ? "true" : "false") << endl;

	float a;
	double b;
	decltype(a + b) c;

	cout << typeid(c).name() << endl; // double

	vector<int> tmp;
	decltype(tmp.begin()) k;

	for (k = tmp.begin(); k != tmp.end(); ++k) {
		// .....
	}

	enum { OK, ERROR} flag; //匿名枚举类型变量
	decltype(flag) flag2;
	cout << typeid(flag2).name() << endl;
}

int func1(int a, int b) {
	return a + b;
}
auto func2(int a, int b) -> int {
	return a + b;
}

auto func3(int a, double b) ->int {
	return a + b;
}

auto func4(int a, double b) ->double {
	return a + b;
}

auto func5(int a, double b) -> decltype(a + b) {
	return a + b;
}

template<class T1, class T2>
auto func6(T1 a, T2 b) -> decltype(a * b) {
	return a * b;
}

int main() {

	int a = 10;
	double b = 11.1;

	cout << "c1: " << func1(a, b) << endl;
	cout << "c2: " << func2(a, b) << endl;
	cout << "c3: " << func3(a, b) << endl;
	cout << "c4: " << func4(a, b) << endl;
	cout << "c5: " << func5(a, b) << endl;

	cout << "c6: " << func6(10, 11.2) << endl;



	return 0;
}
