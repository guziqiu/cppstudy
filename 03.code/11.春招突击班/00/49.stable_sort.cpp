#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

 // 稳定排序
 // 插入排序
void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && num[j] < num[j - 1]; j--) {
            swap(num[j], num[j - 1]);
        }
    }
    return ;
}

void bubble_sort(int *num, int n) {
    int times = 1;
    for (int i = 1; i < n && times; i++) {
        times = 0;
        for (int j = 0; j < n - 1; j++) {
            if (num[j] <= num[j + 1]) continue;
            swap(num[j], num[j + 1]);
            times++;
        }
    }
}


int main() {
    
    return 0;
}

