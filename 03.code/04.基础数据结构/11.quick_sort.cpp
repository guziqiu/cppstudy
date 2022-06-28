#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

#define swap(a, b) {\
    __typeof(a) __temp = b;\
    b = a, a = __temp;\
}

void quick_sortPlus(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (x <= y && num[x] < z) x++;
            while (x <= y && num[y] > z) y--;
            if (x <= y) {
                swap(num[x], num[y]);
                x++, y--;
            }
        } while (x <= y);
        quick_sortPlus(num, x, r);
        r = y;
    }
}

void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
}


void output(int *num, int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << "]" << endl;
    return ;
}
int main() {

    srand(time(0));
    #define MAX_N 20
    int arr[MAX_N];
    randint(arr, MAX_N); // 初始化随机值 
    printf("        ===>   ");
    output(arr, MAX_N);\
    
    printf("quick_sort++ = ");
    quick_sortPlus(arr, 0, MAX_N - 1);
    output(arr, MAX_N);

    #undef MAX_N

    return 0;
}
