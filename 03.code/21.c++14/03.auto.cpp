#include <iostream>
using namespace std;

int main() {

	auto f = [](auto a) { return a; };

	cout << f("c++14") << endl;
	return 0;
}
