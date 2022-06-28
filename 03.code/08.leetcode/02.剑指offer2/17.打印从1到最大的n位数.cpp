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


vector<int> printNumbers(int n) {
	int x = pow(10, n) - 1;
	vector<int> v(x);

	if (0 == n)
	{
		return v;
	}

	for (int i = 0; i < 9; ++i)
	{
		v[i] = i + 1;
	}
	// cout << "9:" << v[8] << endl; 
	
	// cout << x << endl;
	int i = 9;
	while (1)
	{
		if (i == x)
		{
			break;
		}
		v[i] = v[i - 1] + 1;
		++i;
	}


	return v;
	
}



int main() {

	vector<int> n = printNumbers(3);
	
	for (vector<int>::iterator it = n.begin(); it != n.end(); ++it)
	{
		cout << *it << endl;
	}


	return 0;
}
