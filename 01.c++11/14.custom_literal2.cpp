#include <iostream>

using namespace std;

// char const *
// unsigned long long
// long double
// char const *, size_t
// wchar_t const *, size_t
// char16_t const *, size_t
// char32_t const *, size_t

// 只需给第一个参数传参，第二个参数自动推算，测第一个参数的长度，给第二个参数赋值
size_t operator"" _len(char const *str, size_t n) // n = strlen(str)
{
	return n;
}

char const * operator"" _str(char const *buf, size_t n) // n = strlen(str)
{
	return buf;
}

char const * operator"" _test(char const *tmp) // n = strlen(str)
{
	return tmp;
}

int main()
{
	cout << "abc"_len << endl;
	cout << "abc"_str << endl;
	cout << 123_test << endl;

	return 0;
}