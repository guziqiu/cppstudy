#include <iostream>
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

#define swap1(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

#define swap2(a, b) {\
    a ^= b;\
    b ^= a;\
    a ^=b;\
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    
    swap1(a,b);
    printf("swap1 : a = %d, b = %d\n", a, b);
    
    swap1(a,b);
    printf("swap1 : a = %d, b = %d\n", a, b);
    
    return 0;
}

