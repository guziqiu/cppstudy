#include <iostream>
#include <cinttypes>
using namespace std;

int64_t Triangle(int64_t n) {
    return n * (n + 1) >> 1;
}
int64_t Pentagonal(int64_t n) {
    return n * (3 * n - 1) >> 1;
}

int64_t Hexagonal(int64_t n) {
    return n * (2 * n - 1);
}

int binary_search(int64_t (*func)(int64_t), int n, int64_t x) {//二分查找
    int head = 1;
    int tail = n;
    int mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return 1;
        if (func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}


int main() {
    
    int n = 143;
    while (1) {
        n++;
        int64_t temp = Hexagonal(n);
        //if (!binary_search(Triangle, temp, temp)) continue;是六边形一定是三角形
        if (!binary_search(Pentagonal, temp, temp)) continue;
        cout << temp << endl;
        break;
    } 


    return 0;
}

