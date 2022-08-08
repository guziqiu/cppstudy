#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int min(vector<vector<int>> &triangle)
    {
        size_t size = triangle.size();
        for (int i = triangle.size(); i > 0; --i)
        {
            for (int j = 0; j < triangle[size].size(); ++j)
            {
                triangle[size][j] = min(triangle[i][j - 1], triangle[i][j]);
            }
        }

        return 0;
    }
    int minimumTotal(vector<vector<int>>& triangle) {

    }
};

int main()
{

	return 0;
}