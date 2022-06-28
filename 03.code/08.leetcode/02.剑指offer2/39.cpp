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

int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            m[nums[i]]++;
        }
		int ans = 0;
		int num = 0;
        for (auto i = m.begin(); i != m.end(); ++i)
		{
			if (i->first > ans)
			{
				num = i->first;
				ans = i->second;
			}
		}

		return num;
}

int main() {


	return 0;
}
