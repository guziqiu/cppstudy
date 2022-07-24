#include <algorithm> //std::for_each
#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<int> largeNums;
int tmp = 5;

void test1()
{
	for (auto itr = nums.begin(); itr != nums.end(); ++itr)
	{
		if (*itr > tmp)
		{
			largeNums.push_back(*itr);
		}
	}

	for (auto itr = largeNums.begin(); itr != largeNums.end(); ++itr)
	{
		cout << *itr << ", ";
	}
	cout << endl;

}

void func(int &n)
{
	if (n > tmp)
	{
		largeNums.push_back(n);
	}
}

void print(int n)
{
	cout << n << ", ";
}

void test2()
{
	for_each(nums.begin(), nums.end(), func);

	for_each(largeNums.begin(), largeNums.end(), print);
	// for (auto itr = largeNums.begin(); itr != largeNums.end(); ++itr)
	// {
	// 	cout << *itr << ", ";
	// }
	cout << endl;
}

void test3()
{
	for_each(nums.begin(), nums.end(),
		[&] (int &n)
		{
			if (n > tmp)
			{
				largeNums.push_back(n);
			}
		}
		);

	for_each(largeNums.begin(), largeNums.end(),
		[&] (int &n)
		{
			cout << n << ", ";
		});
	cout << endl;
}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		nums.push_back(i + 1);
	}

	

	// 1.传统操作
	test1();

	test2();
	test3();


	return 0;
}