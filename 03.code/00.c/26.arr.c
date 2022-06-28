#include <stdio.h>
#define max_n 100

void func(int *num) {
    //指针变量也是变量，存储地址，
    //传出参数
    //是数组还是指针变量，
    num[0] = 1;

#if 0
    //func(arr);
    printf("sizeof(num) = %lu\n", sizeof(num));
    //表现形式一致性，
    printf("num = %p, num + 1 = %p\n", num, num + 1);
    //

#endif     

}


int main()
{
    int arr[max_n +5] = {0};//将arr的每一位值都初始化为0
        //函数内部申明变量，放在栈区 8MB
    //printf("%d\n",arr[10];
    int n;
    char str[max_n + 5];
    
    printf("sizeof(arr) = %lu\n", sizeof(arr));//420 
    printf("arr = %p, &arr[0] = %p\n", arr, &arr[0]);//==
    printf("arr[1] = %p\n", &arr[1]);
    //arr[1] - arr[0] ==> 4bit
    
    printf("str = %p, str + 1 = %p\n", str, str + 1);//1bit
    //double 8 bit


    //func(arr);
    n = 0;
    scanf("%d", &n);
    func(&n);
    printf("n = %d\n", n);
    return 0;



    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        //scanf("%d", &arr[i]);
        //为什么传地址：程序的功能逻辑需要传变量的地址，通过scanf写入值，通过函数改变函数外部变量的值，需要传入地址
        scanf("%d", arr + i);//等价于
        //
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

