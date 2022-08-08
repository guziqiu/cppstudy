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

vector<vector<bool>> col = vector<vector<bool>>(9, vector<bool>(9, false));

void print(vector<vector<char>>& v)//, vector<vector<bool>> &col)
{
	for_each(v.begin(), v.end(),
	[&](vector<char> &w){
		for_each(w.begin(), w.end(), [&](char &val){ cout << val << ' '; });
		cout << endl;
	});

	// for_each(col.begin(), col.end(),
	// [&](vector<bool> &w){
	// 	for_each(w.begin(), w.end(), [&](bool val){ cout << val << ' '; });
	// 	cout << endl;
	// });
}

int c = 0;

vector<vector<char>> ans;

void dfs(int x, int y, vector<char> &v, vector<char> &row)
{
	if (y == v.size())
	{
		ans.push_back(row);
		return ;
	}

	row.push_back(v[y]);
	if ('.' == row[y])
	{
		char tmp;
		for (int j = 0; j < col[x].size(); ++j)
		{
			if (!col[x][j])
			{
				tmp = j + '0';
			}
		}
		col[x][tmp - '0'] = true;
		row[y] = tmp;
	}
	dfs(x, y + 1, v, row);

}

void solveSudoku(vector<vector<char>>& v)
{
	for_each(v.begin(), v.end(),
		[&](vector<char> &w){
			for_each(w.begin(), w.end(), 
			[&](char &val){ 
				if ('.' != val)
				{
					col[c][val - '0'] = true;
				}
			 });
			++c;
		});


	print(v);//, col);
}

int main()
{
	vector<vector<char>> v = {
		{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}
		};

	solveSudoku(v);

	// char c = 2 + '0';
	// cout << c << endl;
	vector<char> v1 = {'5','3','.','.','7','.','.','.','.'};
	vector<char> row;
	dfs(0, 0, v1, row);
	cout << "----" << endl;
	print(ans);
	// for_each(v1.begin(), v1.end(), [](char &v) { cout << v << " ";});


	return 0;
}
