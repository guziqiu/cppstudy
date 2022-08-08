#include <iostream>
#include <vector>
using namespace std;

int integerBreak(int n) {
	vector<int> dp(n + 1, 0);
	dp[1] = 1;

	for (int i = 0; i < n + 1; ++i)
	{
		for (int j = i - 1; j >= 1; --j)
		{
			dp[i] = max(dp[i], dp[j] * (i - j));
			cout << "max1:" << dp[i] << ", " << dp[j] * (i - j) << endl;
			dp[i] = max(dp[i], j * (i - j));
			cout << "max2:" << dp[i] << ", " << j * (i - j) << endl;
		}
		cout << endl;
	}

	return dp[n];
}

/**
     * 1. 确定dp数组下标含义 分拆数字i，可以得到的最大乘积为dp[i];
     * 2. 递推公式 dp[i] = max(dp[i], (i - j) * j, dp[i - j] * j);
     * 3. 初始化 dp[2] = 1;
     * 4. 遍历顺序 从前向后遍历就可以;
     * 5. 推导结果;
     */
int integerBreak2(int n)
{
	/* 定义dp数组 */
	vector<int> dp(n + 1, 0);
	/* dp数组初始化 */
	dp[2] = 1;
	/* 从前向后遍历 */
	cout << "dp[i] " << ",dp[i - j] * j" << ",((i - j) * j)" << endl;
	for (int i = 3; i <= n ; i++)
	{
		/* j遍历到小于i的值 */
		for (int j = 1; j < i - 1; j++)
		{
			cout << dp[i] << " ";
			dp[i] = max(dp[i], dp[i - j] * j);
			cout << dp[i - j] * j << " ";
			dp[i] = max(dp[i], ((i - j) * j));
			cout << ((i - j) * j) << " | ";
		}
		cout << "dp[" << i << "]->" << dp[i] << endl;
	}
	return dp[n];
}

int integerBreak3(int n)
{
	if (2 == n)
	{
		return 1;
	}

	return 0;
}

int main() {

	cout << integerBreak2(10) << endl;
	return 0;
}
