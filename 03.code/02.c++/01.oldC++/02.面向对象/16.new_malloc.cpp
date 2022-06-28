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

class A {
public:
    A() {
        cout << "default constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }

};

int main() {
    int n = 10;

    cout << "malloc int : " << endl;
    int *data = (int *)malloc(sizeof(int) * n);
    free(data);
    cout << "new int : " << endl;
    int *data2 = new int[n]; // 用法简单
    delete[] data2; // delete连续的数组空间

    cout << "malloc A : " << endl;
    A *Adata1 = (A *)malloc(sizeof(A) * n);
    for (int i = 0; i < n; i++) { // 为每一个变量赋值 
        new(Adata1 + i) A();// 原地构造 new(首地址) A():要调用那个类型的构造
        // cin >> Adata1 + 1;
    }
    free(Adata1);
    cout << "new A : " << endl;
    A *Adata2 = new A[10];
    A *Adata3 = new A;
    delete[] Adata2;
    // delete[] Adata2;
    delete Adata3; // 单一变量不需要加[]
    



    return 0;
}
