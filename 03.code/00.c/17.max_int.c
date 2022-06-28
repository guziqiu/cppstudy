#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>

int max_int (int n, ...) {
    int ans = INT32_MIN;
    va_list arg;
    va_start(arg,n);
    while (n--) {
        int temp = va_arg(arg, int);
        if (temp > ans) ans =temp;
    }
    va_end(arg);
    return ans;
}

int main()
{
    printf("%d", max_int(5, 34, 12, 12,34,56, 199));
    return 0;
}

