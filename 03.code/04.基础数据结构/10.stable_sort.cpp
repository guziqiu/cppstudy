#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

#define swap(a, b) {\
    a ^= b; b^= a; a ^= b;\
}

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s : \n", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

//插入排序
void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && num[j] < num[j - 1]; j--) {
            swap(num[j], num[j - 1]);
        }
    }
    return ;
}

//冒泡排序
void bubble_sort(int *num, int n) {
    int times;
    for (int i = 1; i < n && times; i++) {//times,如果有一轮排序没有发生互换位置，则终止循环
        times = 0;
        for (int j = 0; j < n - 1; j++) {
            if (num[j] <= num[j+ 1]) continue;
            swap(num[j], num[j + 1]);
            times++;
            //if (num[j] > num[j + 1]) {
            //    swap(num[j], num[j + 1]);
            //    times++;
            //}
        }
    }
}

//归并排序
void merage_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && num[r] < num[l]) {
            swap(num[r], num[l]);
        }
        return ;
    }
    //数组分为两段
    int mid = (l + r) >> 1;
    merage_sort(num, l, mid);
    merage_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    //将两个有序的数组合并为一个
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {//当数组中有元素时进行合并
        if (p2 > r || (p1 <= mid && num[p1] < num[p2])) {
            //p2 > r : 第二个数组已经没有元素了，p1 <= mid,第一个元素还有元素，
            temp[k++] = num[p1++];//将两个数组中较小的那个值，赋值给temp,temp成升序排列
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));//将temp拷贝到num中
    free(temp);
    return ;
}

void randint(int *num, int n) {//随机生成100以内的数字
    while (n--) num[n] = rand() % 100;
    return ;
}

void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    //随机生成数组
    srand(time(0));
    #define max_n 20
    int arr[max_n];
    randint(arr, max_n);
    TEST(arr, max_n, insert_sort, num, max_n);
    TEST(arr, max_n, bubble_sort, num, max_n);
    TEST(arr, max_n, merage_sort, num, 0, max_n - 1);

    #undef max_n



    return 0;
}