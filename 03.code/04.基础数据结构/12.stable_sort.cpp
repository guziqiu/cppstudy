#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

void insert_sort(int *num, int n) {
    for (int i = 1; i < n - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (num[ind] > num[j]) ind = j;
        }
        int t = num[ind];
        num[ind] = num[i];
        num[i] = t;
    }
    return ;
}

void quick_sort(int *num, int l, int r) {
    if (l > r) return ;
    int x = l, y = r, z = num[x];
    while (x < y) {
        while (x < y && num[y] > z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] < z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

void quick_sortPlus(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (x <= y && num[x] < z) x++;
            while (x <= y && num[y] > z) y--;
            if (x <= y) {
                int t = num[x];
                num[x] = num[y];
                num[y] = t;
            }
        } while (x <= y);
        quick_sortPlus(num, x, r);
        r = y;
    }
}


int main() {


    return 0;
}