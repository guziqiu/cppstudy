#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAX_N 100

int binary_search(int *arr, int n, int x) { // 二分查找
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == x) return 1;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

// 二分查找实现开平方根
#define EPSL 1e-8
double binary_search(double n) {
    double head = 0, tail = n, mid;
    if (n < 1.0) tail = 1.0; // 解决 0 < n < 1 的问题
    while (tail - head > EPSL) {
        mid = (head + tail) / 2.0;
        //if (fabs(mid * mid - n < EPSL)) return mid;
        if (mid * mid < n) head = mid;
        else tail = mid;
    }
    return head;
}


int main() {
    // double n;
    // cin >> n;
    // cout << "binary_search_sqrt:" << binary_search(n) << endl;
    // cout << "srqt:" << sqrt(n) << endl;
    // return 0;

    int arr[MAX_N] = {0};
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;

    while (~scanf("%d", &x)) {
        printf("%s\n", binary_search(arr, n, x) ? "YES" : "NO");
    }



    return 0;
}

