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


int minArray(vector<int>& numbers)
{
	int r = numbers.size() - 1;
	size_t l = 0;
	while (l < r)
	{
		if (numbers[l] < numbers[r])
		{
			--r;
		}
		else if (numbers[l] >= numbers[r])
		{
			++l;
		}
	}
	return numbers[l];
}



int main() {

	vector<int> n(4);
	n[0] = 3;
	n[1] = 4;
	n[2] = 5;
	n[3] = 1;
	n[4] = 2;

	cout << minArray(n) << endl;


	return 0;
}
