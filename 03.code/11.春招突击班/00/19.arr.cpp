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

#define MAX_N 100

void func(int *p) {// p 一个指针变量，指向整型，为什么数组可以指向地址，指向数组收地址，加上地址偏移量，就可以访问整个数组
    printf("func : \n");
    return ;
}

void func2(int p[MAX_N + 5][200]) {// 二维数组传参
    printf("func2 : \n");
}
void func3(int p[][200]) {// 二维数组传参
    printf("func2 : \n");
}
void func4(int (*p)[200]) {// 二维数组传参
    printf("func2 : \n");
}

int main() {
   int arr[MAX_N + 5] = {0};
   int arr1[MAX_N + 5][200] = {0};
   for (int i = 0; i < 5; i++) {
       //scanf("%d", &arr[i]);
       scanf("%d", arr + i);// arr数组
   }
   func(arr);
   func2(arr1);
   func3(arr1);
   func4(arr1);
   return 0;
}
