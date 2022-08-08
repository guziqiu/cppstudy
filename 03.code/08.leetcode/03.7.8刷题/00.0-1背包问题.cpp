#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 有一个背包，他的容量为C(Capacity)。现在又n种不同的物品，编号为0....n - 1 ,其中每一件物品的重量为w(i),价值为v(i).问可以向这个背包中盛放哪些物品，使得在不超过背包容量的基础上，物品的总价值最大
// 暴力解法：每一件物品都可以放进背包，也可以不放进去
// 动态规划：
// 状态定义：
// F(n,C) ：将n个物品放进容量为C的背包，使得价值最大
// F(i, c) = F(i - 1, c)                           // i不放入背包
//         = v(i) + F(i - 1, c- W(i))             // i放入背包
class Solution
{
private:
	// 用[0 ... index]的物品，填充容积为C的背包的最大价值
	int bestValue(const vector<int> &w, const vector<int> v, int index, int c)
	{
		if (index < 0 || c <= 0)
		{
			return 0;
		}

		int res = bestValue(w, v, index - 1, c);
		if (c >= w[index])
		{
			res = max(res, v[index] + bestValue(w, v, index - 1, c - w[index]));
		}

		return res;
	}

	// 动态规划 + 记忆化搜索
	vector<vector<int>> memo; // 
	int bestValue2(const vector<int> &w, const vector<int> v, int index, int c)
	{
		if (index < 0 || c <= 0)
		{
			return 0;
		}

		if (memo[index][c] != -1)
		{
			return memo[index][c];
		}

		int res = bestValue(w, v, index - 1, c);
		if (c >= w[index])
		{
			res = max(res, v[index] + bestValue(w, v, index - 1, c - w[index]));
		}

		memo[index][c] = res;

		return res;
	}
public:
	int knapspack01(const vector<int> &w, const vector<int> &v, int c)
	{
		int n = w.size();
		return bestValue(w, v, n - 1, c);
	}
	int knapspack02(const vector<int> &w, const vector<int> &v, int c)
	{
		int n = w.size();

		memo = vector<vector<int>> (n, vector<int>(c + 1, -1)); // n * C + 1
		return bestValue2(w, v, n - 1, c);
	}
	int knapspack03(const vector<int> &w, const vector<int> &v, int c)
	{
		int n = w.size();
		if (0 == n)
		{
			return 0;
		}
		vector<vector<int>> memo(n, vector<int>(c + 1, -1));

		// 先考虑0号物品
		for (int j = 0; j <= c; ++j)
		{
			memo[0][j] = ( j >= w[0] ? v[0] : 0);
		}

		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j <= c; ++j)
			{
				memo[i][j] = memo[i - 1][j];
				if (j >= w[i])
				{
					memo[i][j] = max( memo[i][j], v[i] + memo[i - 1][j - w[i]]);
				}
			}
		}

		return memo[n - 1][c];
	}

	int knapspack04(const vector<int> &w, const vector<int> &v, int c)
	{
		int n = w.size();
		if (0 == n)
		{
			return 0;
		}
		vector<vector<int>> memo(2, vector<int>(c + 1, -1));

		// 先考虑0号物品
		for (int j = 0; j <= c; ++j)
		{
			memo[0][j] = ( j >= w[0] ? v[0] : 0);
		}

		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j <= c; ++j)
			{
				memo[i % 2][j] = memo[(i - 1) % 2][j];
				if (j >= w[i])
				{
					memo[i % 2][j] = max( memo[i % 2][j], v[i] + memo[(i - 1) % 2][j - w[i]]);
				}
			}
		}

		return memo[(n - 1) % 2][c];
	}

};


int main() {

	vector<int> w = {1, 2, 3};
	vector<int> v = {6, 10, 12};
	int c = 5;

	Solution sol;
	cout << sol.knapspack01(w, v, c) << endl;
	cout << sol.knapspack02(w, v, c) << endl;
	cout << sol.knapspack03(w, v, c) << endl;
	cout << sol.knapspack04(w, v, c) << endl;


	return 0;
}
