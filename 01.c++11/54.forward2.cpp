#include <iostream>
using namespace std;

template<class T> void func(const T &)
{
	cout << "const T &" << endl;
}

// template<class T> void func(T &)
// {
// 	cout << "T &" << endl;
// }

// template<class T> void func(T &&)
// {
// 	cout << "T &&" << endl;
// }

template<class T> void forward_val(T &&tmp) // const T && 参数为右值引用
{
	func( std::forward<T>(tmp) ); // 保持参数的左值、右值属性
}

int main()
{
	int a = 0;
	const int &b = 1;

	// 需要给forward_val重载两个版本 const T& , T&
	forward_val(a); // T &      // -> T &
	forward_val(b); // const T &  // int & -> T &
	forward_val(111); // T &&  //发生引用重叠 const & -> T&&

	return 0;
}