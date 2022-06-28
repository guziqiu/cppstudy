#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char str[11] = {0};
    int a;
    
    char ch[4];
    while(~scanf("%s%d", ch, &a)) {
        printf("ch = %c, a = %d\n", ch[0], a);
        //%c可以读入任何字符，通过分隔符区分参数
    }
    


    return 0;

    while(~scanf("%d", &n)) {
        sprintf(str, "%x", n);
        printf("%s has %ld digit!\n", str, strlen(str));
    }
    return 0;
}

