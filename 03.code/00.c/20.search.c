#include <stdio.h>

int binary_search(int (*arr)(int), int x, int n) {
    int head = 0;
    int tail = n - 1;
    int mid ;
    while (head <= tail) {
        mid = (tail + head ) / 2;
        if (arr(mid) == x) return mid;
        if(arr(mid) > x) {
            mid -= 1;
            tail = mid;
        }
        else {
            mid += 1;
            head = mid;
        }
    }

    return -1;
}

int binary_search1(int *arr, int x, int n) {
   int head = 0;
   int tail = n - 1;
   int mid;
   while(head <= tail) {
       mid = (head + tail) >> 1;
       if (arr[mid] == x) return mid;
       if (arr[mid] < x) head = mid + 1;
       else tail = mid - 1;
   }

    return -1;
}
int func(int x) {
    return x;
}
int main()
{
    int arr[100] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
       arr[i] = i;
       //scanf("%d", &arr[i]);
    }
    int x;
    while(~scanf("%d", &x)) {
        printf("binary_search ==>%d\n", binary_search(func, x, n));

        printf("binary_search1==> %d\n", binary_search1(arr, x, n));
    }
    
    return 0;
}

