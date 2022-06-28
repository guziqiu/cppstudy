#include <iostream>
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



typedef pair<int, int> PII;

class BigInt : public vector<int> {
public:
    BigInt(int x) {
        push_back(x);
        proccess_digit();
    }
    void operator*=(int x);
    void operator/=(int x);
    BigInt operator/(int x);
    bool operator<(const BigInt &) const;
    bool operator>(const BigInt &) const;
private:
    void proccess_digit();
};
#if 0
BigInt::BigInt(x) {
    push_back(x);
    proccess_digit();
}
#endif

ostream &operator<<(ostream &out, const BigInt &a) {//重载左移运算符
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

void BigInt::proccess_digit() {//处理进位
    for (int i = 0; i < size(); i++) {
        if (at(i) < 10) continue;
        if (i + 1 == size()) push_back(0);
        at(i + 1) += at(i) / 10;
        at(i) %= 10;
    }
    while (size() > 1 && at(size() - 1) == 0) pop_back();
    return ;
}

void BigInt::operator*=(int x) {// *=
    for (int i = 0; i < size(); i++) at(i) *= x;
    proccess_digit();
    return ;
}

void BigInt::operator/=(int x) {
    int y = 0;
    for (int i = size() - 1; i >= 0; i--) {// /=
        y = y * 10 + at(i);
        at(i) = y / x;
        y %= x;
    }
     proccess_digit();   
     return ;
}

BigInt BigInt::operator/(int x) {//除法
    BigInt ret(*this);
    ret /= x;
    return  ret;
}

bool BigInt::operator<(const BigInt &a) const{
    if (size() - a.size()) return size() < a.size();//位数不相同，直接返回
    for (int i = size() - 1; i >= 0; i--) {
        if (at(i) - a[i]) return at(i) < a[i];
    }
    return false;
}

bool BigInt::operator>(const BigInt &a) const {
    return a < (*this);
}

int main() {
    vector<PII> arr;
    int n;
    cin >> n;

    for (int i = 0, a, b; i <= n; i++) {
        cin >> a >> b;
        arr.push_back(PII(a, b));
    }
    sort(arr.begin() + 1, arr.end(), 
         [](const PII &x, const PII &y){ 
            return x.first * x.second < y.first * y.second; 
         }
    );

    BigInt p = arr[0].first;//当前累乘结果
    BigInt ans = 0;//获得最多金币者获得多少金币

    for (int i = 1; i <= n; i++) {
        BigInt temp = p / arr[i].second;
        ans = max(ans, temp);
        p *= arr[i].first;
    }

    cout << ans << endl;

    
    return 0;
}

