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

// C
struct Test
{
	int a;
	int b;
	char name[50];
};

void test()
{
	struct Test tmp = {1, 2, "string"}; // 列表初始化

	int a = 1;
	int b = { 1 }; // 列表初始化
	int c {2}; // 列表初始化

	int arr1[] = {1, 2, 3};
	int arr2[] = {1, 2, 3};
}

// C中的类型收窄

void test1()
{
	int a = 1024;
	char b = a; // ok ,但是丢失部分数据
	printf("b = %d\n", b); // b = 0
}

// c++ 列表初始化防止类型收窄
void test2()
{
	int a = 1024;
	// char b = { a }; // errord+

	// c++ 11
	vector<vector<int>> v = {{1}, {2}, {3, 4}};
}
int main() {
	test();
	test1();
	test2();

	return 0;
}
