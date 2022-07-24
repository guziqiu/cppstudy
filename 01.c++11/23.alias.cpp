#include <iostream>
#include <type_traits>
using namespace std;

// 通过typedef 给一个类型起别名 ，不能新建类型
typedef int int32;

using my_int = int; // C++ 11 方式


int main() {

	// is_same: 判断两个类型是否一致， 如果是 返回 true， 否则返回false
	cout << std::is_same<int32, my_int>::value << endl;

	return 0;
}
