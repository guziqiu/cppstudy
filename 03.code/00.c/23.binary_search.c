#include <stdio.h>

int binary_search(int *arr, int n, int x) {
    int head = 0;
    int tail = n - 1;
    int mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid -  1;
    }
    return -1;
}

int main()
{
    int n, x;
    scanf("%d", &n);
    int arr[100];
    for (int i = 0;i < n; i++)  scanf("%d", &arr[i]);

    while (~scanf("%d", &x)) {
       printf("%d\n", binary_search(arr, n, x));
    }
    
    return 0;
}

