#include <stdio.h>
#include <string.h>




int main()
{
    char str[11] = {0};
    int n;
    while(~scanf("%d", &n)) {
        sprintf(str, "%x", n);
        printf("%s has %lu digits!\n", str, strlen(str));
    }









    return 0;
}

