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

string reverseWords(string s) {
	if (s.empty()) return "";
	string result;
	vector<string> v;

	string tmp;
	for (int i = 0; i < s.size(); ++i)
	{
		if ((' ' == *tmp.rbegin() || tmp.empty()) && ' ' == s[i]) {
			continue;
		}
		tmp += s[i];
	}
	if (' ' == tmp[tmp.size() - 1]) tmp = tmp.substr(0, tmp.size() - 1);
	if (tmp.empty()) return "";

	int l = 0;
	int i = 0;
	while (i < tmp.size()) {
		if (' ' == tmp[i]) {
			v.push_back(tmp.substr(l, i - l));
			l = i + 1;
		}
		++i;
	}

	v.push_back(tmp.substr(l, i));

	for (int i = v.size() - 1; i >= 0; --i) {
		result += v[i];
		if (i != 0) result += " ";
	}

	return result;
}

int main() {
	string str(" ");


	cout << reverseWords(str) << endl;

	cout << str.substr(0, str.size() - 1) << endl;


	return 0;
}
