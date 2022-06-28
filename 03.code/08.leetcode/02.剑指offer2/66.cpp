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

int add(int a, int b) {

	while (b != 0) {
        int temp = a ^ b;
        b = (a & b) << 1;
        a = temp;
    }
    return a;


}

int main() {
	// int arr[] = {1, 1};
	int a = -1;
	int b = 2;

	
	
	cout << a << endl;

	cout << add(a, b) << endl;
	vector<int> v;
	v.c

	return 0;
}
