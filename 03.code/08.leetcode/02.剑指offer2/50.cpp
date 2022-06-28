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
 char firstUniqChar(string s) {
        if (s.empty())
        {
            return ' ';
        }
        map<char, int> m;
        for (size_t i = 0; i < s.size(); ++i)
        {
            m[s[i]]++;
        }
        for (map<char, int>::iterator it = m.begin(); it != m.end(); ++it)
        {
			cout << it->first << ":" << it->second << endl;
            // if (m[it->first] == 1)
            // {
            //     return it->first;
            // }
        }

        return ' ';
    }

int main() {

	cout << firstUniqChar("leetcode") << endl;

	return 0;
}
