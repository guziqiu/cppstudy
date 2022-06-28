#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<algorithm>
using namespace std;
bool findNumberIn2DArray(vector<vector<int> >& matrix, int target) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == target) return true;
        }
    }
    return false;
}
class Solution {
public:
    bool findNumberIn2DArray1(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1, j = 0;
        while(i >= 0 && j < matrix[0].size()) {
            if(matrix[i][j] > target) i--;
            else if(matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }
};
 

int main() {

    return 0;
}