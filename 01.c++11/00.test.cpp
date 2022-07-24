#include <iostream>
#include <list>
using namespace std;

int main() {

	list<int> l;
	l.push_back(5);
	l.push_back(23);
	l.push_back(456);
	l.push_back(9);

	int num = 0;
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		num++;
		if (*it == 456)
		{
			break;
		}
	}

	cout << num << endl;

	return 0;
}
