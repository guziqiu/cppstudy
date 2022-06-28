#include <iostream>
using namespace std;


template<int i, int n>
struct getNextI {
    static constexpr int r = (n % i ? i + 1 : 0);
};

template<int i, int n>
struct getNextN {
    static constexpr int r = (i * i <= n ? n : 0);
};

template<int i, int n>
struct __test_prime {
    static constexpr int r = __test_prime<getNextI<i, n>::r, getNextN<i, n>::r>::r;
};
template<int n>
struct __test_prime<0, n> {
    static constexpr int r = 0;
};

template<int i>
struct __test_prime<i, 0> {
    static constexpr int r = 1;
};
template<>
struct __test_prime<0, 0> {
    static constexpr int r = 1;
};

template<int n>
struct if_condition {
    static constexpr const char *r = (n ? "YES" : "NO");
};

template<int n>
struct is_prime {
    static constexpr const char * r = if_condition<__test_prime<2, n>::r>::r;
};



int main() {

    cout << is_prime<2>::r << endl; // 1
    cout << is_prime<13>::r << endl; // 1
    cout << is_prime<25>::r << endl; // 0
    cout << is_prime<27>::r << endl; // 0
    cout << is_prime<9973>::r << endl; // 1
    cout << is_prime<1234>::r << endl; // 0


    return 0;
}

