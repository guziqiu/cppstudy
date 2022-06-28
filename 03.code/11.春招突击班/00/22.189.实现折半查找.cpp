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
#define MAX_N 1000000

int binary_search(int *arr, int n, int ind) {
    //if (ind < arr[1] || ind > arr[n]) return 0;
    int head = 1;
    int tail = n;
    int mid;

    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (ind == arr[mid]) return mid;
        if (ind > arr[mid]) head = mid + 1;
        else tail = mid - 1;  
    }
    return 0;
}

int main() {
    int n, k;// 第一行输入两个整数𝑁（ 1≤𝑁≤106 ）和 𝐾（1≤𝐾≤106 ），分别表示给定的整数总个数和待查找的数的个数；
    scanf("%d%d", &n, &k);
    int arr[MAX_N + 5];
    int num[MAX_N + 5];
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }

    for (int i = 1; i <= k; i++) {
        scanf("%d", num + i);
    }
    for (int i = 0; i < k; i++) {
        i && printf(" "); 
        printf("%d", binary_search(arr, n, num[i + 1]));
    }
    printf("\n");



    return 0;
}
