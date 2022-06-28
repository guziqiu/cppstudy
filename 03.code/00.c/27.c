#include <stdio.h>


void func(int (*num)[4]) {
    printf("arr = %p, arr + 1 = %p\n", num, num + 1);//16bit
}
void func1(int **num) {
    printf("num = %p, num + 1 = %p\n", num, num + 1);//16bit
}
int main()
{
    int arr[2][4] = {0};

    func(arr);
    printf("arr = %p, atrr + 1 = %p\n", arr, arr + 1);
    int **num;//指针的指针

    func1(num);

    return 0;
}

