#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

ostream &operator<<(ostream &out, const vector<int> &a) {
    for (auto x : a) {
        out << x << " ";
    }
    return out;
}

bool cmp(int a, int b) {     
    //return a < b;// a排在b前面：a < b,从小到大
    return a > b;// a排在b后面：a > b,从大到小
}

class CMP {
public :
    CMP(int z = 0) : z(z) { // z == 0 less z = 1 greater
        
    }
    bool operator()(int a, int b) {
        // return a > b;
        return (a < b) ^ !!(z); 
    }
    int z;
};

int main() {
    vector<int> arr;
    int n = 9;
    //cin >> n;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int temp = rand() % 100;
        arr.push_back(temp);
    }

    //sort(arr.begin(), arr.end(), cmp; // cmp函数
    //sort(arr.begin(), arr.end(), CMP()); //  cmp匿名对象， 仿函数
    CMP cmp2;
    //sort(arr.begin(), arr.end(), cmp2); //  cmp2对象 相对于函数仿函数功能更加强大
    //sort(arr.begin(), arr.end(), CMP()); //  cmp匿名对象， 默认从小到大排序
    sort(arr.begin(), arr.end(), CMP(1)); //  cmp匿名对象， 传参1 从 大到小排序  外在表现的像一个函数 实际上比函数更加强大
    cout << arr << endl;



    return 0;
}

