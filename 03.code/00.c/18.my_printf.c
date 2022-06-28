
#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

int reverse_num(int x,int *temp) {
    int digit = 0;
    do {
        digit++;
        *temp = *temp * 10 + x % 10;
        x /= 10;
    } while (x);
    return digit;
}

int output_num(int num, int digit) {
    int cnt = 0;
    while(digit--) {
        putchar(num % 10 + '0');
        cnt++;
        num /= 10;
    }
    return  cnt;
}

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    #define PUTC(a) putchar(a),++cnt

    for (int i =0; frm[i]; i++) {
        switch (frm[i]) {
        case '%': {
                      switch (frm[++i]) {
                      case '%':  PUTC(frm[i]);    break;
                      case 'd':{
                        int x = va_arg(arg, int);
                        uint32_t xx = 0;
                        if (x < 0) PUTC('-'),xx = -x;
                        else xx = x;
                        int x1 = xx / 100000, x2 = xx % 100000;
                        int temp1 = 0, temp2 = 0;
                        int digit1 = reverse_num(x1, &temp1);
                        int digit2 = reverse_num(x2, &temp2);
                        int digit3 = 0;
                        if (x1) digit3 = 5 - digit2;
                        else digit1 = 0;
                        cnt += output_num(temp1, digit1);
                        cnt += output_num(0,digit3);
                        cnt += output_num(temp2, digit2);
                        } break;
                      case 's': {
                          const char *str = va_arg(arg, const char *);
                          for (int i = 0; str[i]; i++) {
                                PUTC(str[i]);
                          }
                               }
                      }
                      break;
                }
            default : {PUTC(frm[i]); break;}
        }
       // putchar(frm[i]);

    }

    #undef PUTC
    va_end(arg);
    
    return cnt;
}

int main() {
    printf("printf == > hello, world!\n");
    printf("my_printf ==> %d\n\n", my_printf("hello, world!\n"));

    int a = 123;
    printf("int (a) = %d\n", a);
    my_printf("my_printf ==> int (a) = %d\n\n", a);

    printf("int (0) = %d\n", 0);
    my_printf("my_printf ==> int (0) = %d\n\n", 0);

    
    printf("int (10000) = %d\n", 10000);
    my_printf("my_printf ==> int (10000) = %d\n\n", 10000);

    printf("int (10050) = %d\n", 10050);
    my_printf("my_printf ==> int (10050) = %d\n\n", 10050);

    printf("int (-123) = %d\n", -123);
    my_printf("my_printf ==> int (-123) = %d\n\n", -123);
    
    printf("int (INT32_MAX) = %d\n", INT32_MAX);
    my_printf("my_printf ==> int (INT32_MAX) = %d\n\n", INT32_MAX);
    
    printf("int (INT32_MIN) = %d\n", INT32_MIN);
    my_printf("my_printf ==> int (INT32_MIN) = %d\n\n", INT32_MIN);
    
    char str[] = "I love China";
    printf("(str) = %s\n", str);
    my_printf("my_printf ==> str = %s\n\n", str);
    
    
    int n;
    while (~scanf("%d", &n)) {
        printf(" has %d digits!\n", printf("printf %d", n) - 7);
        my_printf(" has %d digits!\n\n", my_printf("my_printf %d", n) - 10);
    
    }
   return 0;
}
