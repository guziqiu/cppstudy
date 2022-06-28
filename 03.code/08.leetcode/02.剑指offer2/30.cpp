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

int main() {
		vector<int> v;
		v.push_back(2);
		v.push_back(1);
		v.push_back(3);
		cout << v[0] << endl;
		sort(v.begin(), v.end(), less<int>());
		cout << v[0] << endl;
		// v.erase();
		stack<int> s;
		// s.
		v.erase(v.begin());
		// cout << v.size() << endl;


	return 0;
}
