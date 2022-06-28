#include <iostream>
#include <cstdio>
using namespace std;

// 00000000011111111 找第一个1
int binary_search1(int *arr, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == x) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

// 11111111111110000000  找最后一个1
int binary_search2(int *arr, int n, int x) {
    int head = -1, tail = n - 1, mid; // 虚拟头指针 -1
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (arr[mid] == x) head = mid;
        else tail = mid - 1;
    }
    return head;
}

int main() {
    //int arr1[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int arr1[10] = {0};
    int arr2[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int arr3[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
    printf("%d\n", binary_search2(arr1, 10, 1));

    return 0;
}

