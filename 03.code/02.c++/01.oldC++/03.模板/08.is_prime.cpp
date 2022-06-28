#include <iostream>
using namespace std;

template<int N>
struct is_prime {
    static constexpr int r = 0;
};



// 模板类实现递归 循环求和
template<int n>
struct sum {
    static constexpr int r = n + sum<n - 1>::r;
};

template<>
struct sum<1> { // 特化版本 递归终结处
    static constexpr int r = 1;
};

// 模板类实现  if判断
template<int n>
struct getBad {
    static constexpr int r = (n <= 5);
};
template<int n>
struct getGood {
    static constexpr int r = (n > 5);
};

template<int n, int m>struct judge;
template<>
struct judge<1, 0> {
    static constexpr char *const r = (char *)"bad";
};
template<>
struct judge<0, 1> {
    static constexpr char *const r = (char *)"good";
};

template<int n>
struct score {
    static constexpr char *const r = judge<getBad<n>::r, getGood<n>::r>::r; 
};


//is_even 判断奇数偶数
template<int n>
struct isEven {
    static constexpr int r = !(n % 2);
};
template<int n>struct judge1;
template<>
struct judge1<0> {
    static constexpr char *const r = (char *)"no";
};
template<>
struct judge1<1> {
    static constexpr char *const r = (char *)"yes";
};
template<int n>
struct is_even {
    static constexpr char *r = judge1<isEven<n>::r>::r;
};



int main() {
    cout << sum<5>::r << endl; // 1~5的和  模板类实现求和
    cout << score<10>::r << endl; // good 模板实现分支判断
    cout << score<4>::r << endl;  // bad
    cout << is_even<3>::r << endl; // no   判断奇数偶数
    cout << is_even<4>::r << endl; // &yes

    cout << is_prime<2>::r << endl; // 1
    cout << is_prime<13>::r << endl; // 1
    cout << is_prime<25>::r << endl; // 0
    cout << is_prime<27>::r << endl; // 0
    cout << is_prime<9973>::r << endl; // 1
    cout << is_prime<1234>::r << endl; // 0




    return 0;
}

