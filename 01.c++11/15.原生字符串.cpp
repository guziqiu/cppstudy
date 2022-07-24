#include <iostream>
using namespace std;

int main() {
	cout << R"()" << endl;
	cout << R"(hello, \nworld)" << endl;
	cout << R"(hello, \n
				world)" << endl;
	cout << "(hello, \n\
				world)" << endl;

	string str = R"(hello, \4 \r
		abc,mike,
		heo\n)";

	cout << str << endl;

	return 0;
}
