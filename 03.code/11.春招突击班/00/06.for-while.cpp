#include <iostream>
using namespace std;

int reverse_num(int n) {//回文判断
    int sum = 0; 
    int x = n;
    while (x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return sum == n;
}

int main() {

    //回文判断
    int n;
    while (~scanf("%d", &n)) {
        cout << "reverse_num1 : " << endl; 
        if (reverse_num(n)) cout << "Yes" << endl;
        else cout << "No" << endl;

        cout << "reverse_num2 : " << endl;
        cout << (reverse_num(n) ? "Yes" : "No") << endl;
    }
    return 0;

    //短路原则控制输出格式
    for (int i = 10; i >= 0; i--) {
        printf("%d", i);
        if (i != 0) printf(" ");
    }
    printf("\n");
    for (int i = 10; i >= 0; i--) {
        printf("%d", i);
        i && printf(" ");
    }
    printf("\n");

    int a = 0;
    int b = 0;
    

    //短路原则
    if ((a++) && (b++)) {
        cout << "a = " << a << ", b = " << b << endl;
        printf("true\n");
    } else {
        cout << "a = " << a << ", b = " << b << endl;
        printf("false\n");
    }

    cout << "a = " << a << ", b = " << b << endl;

    if ((b++) || (a++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("a = %d, b = %d\n", a, b);

    return 0;
}

