#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
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
#define MAX_N 100000

int arr[MAX_N + 5] = {0};
int ind[MAX_N + 5] = {0};

int find(int *ind, int n, int x) {
    for (int i = 0; i <= n; i++) {
        //cout << "ind i = " << i << " " << ind[i]  << "x = " << x << endl;
        if (ind[i] == x) return i;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ind[i] = arr[i];
        //if (arr[i] < 0) arr[i] = -arr[i];
        heap_sort(ind, i);
        output(ind, i);
        //printf("arr[%d] = %d , ind[%d] = %d\n", i, arr[i], 0, ind[0]);
        i  && printf("%d %d\n", (arr[i] - ind[1]), find(arr, i, ind[0])); 
    }

    for (int j = 0; j < n; j++) {
        //cout << ind[j] << " ";
    }
    cout << endl;

    return 0;
}

