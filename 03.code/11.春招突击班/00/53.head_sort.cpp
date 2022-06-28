#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

void downUpdate(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {//堆中还有元素就可以进行调整
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[ind], arr[temp]);
        ind = temp;
    }
    return ;
}

void heap_sort(int *arr, int n) { // 堆排序 线性建堆
    arr -= 1;
    for (int i = n >> 1; i >= 1; i--) {
        downUpdate(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(arr[i], arr[1]);
        downUpdate(arr, i - 1, 1); // 向下维护
    }
}

void output(int *arr, int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        i && cout << ", ";
        cout << arr[i];
    }
    cout << "]" << endl;;
}


int main() {
    srand(time(0));
    #define MAX_N 20
    int *arr = (int *)malloc(sizeof(int) * (MAX_N));
    for (int i = 0; i < MAX_N; i++) {
        arr[i] = rand() % 100;
    }
    output(arr, MAX_N);
    heap_sort(arr, MAX_N);
    output(arr, MAX_N);
    free(arr);
    #undef MAX_N 
    
    return 0;
}

