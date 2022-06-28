#include <iostream>
using namespace std;

namespace spaceA {
	int g_a = 10;

	namespace spaceB {
		struct teacher
		{
			int id;
		};
	}
}



int main()
{
	cout << spaceA::g_a << endl;

	// 1
	// spaceA::spaceB::teacher t1;
	// using spaceA::spaceB::teacher;

	// 2
	// teacher t1;
	using namespace::spaceA::spaceB;
	// teacher t1;
	// 2
	struct teacher t1;
	t1.id = 10;
	cout << t1.id << endl;


}