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

class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int l = 0;
        int r = t.size() - 1;

        int sl = 0;
        int sr = s.size() - 1;
		cout << "ans : " << r << ", "<< sr << endl;
        while (l < r && sl <= sr)
        {
			// cout << l << ", " << r << endl;
			// cout << sl << ", " << sr << endl;
            if (s[sl] == t[l])
            {
				cout << "l:" << s[sl] << "," << t[l] << endl;
                ++sl;
            }
            if (s[sr] == t[r])
            {
				 cout << sr << ", " << sr << endl;
				cout << "r:" << s[sr] << "," << t[r] << endl;
                --sr;
            }
            --r;
            ++l;
        }
		// cout << 
		if (s[sl] == t[l]) ++sl;
		// cout << s[sl] <<"," << t[l] << endl;
		// cout << sl << "," << sr << endl;
        return sl > sr;

    }
};

int main() {

	Solution s;
	// cout << s.isSubsequence("axc", "ahbgdc") << endl;
	cout << (s.isSubsequence("b",
"abc") == 1 ? "true" : "false") << endl;

	return 0;
}
