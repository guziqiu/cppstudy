#include <stdio.h>
#include <string.h>
#define max_n 150
int main()
{
    int n;
    char name[max_n] = {0};
    char ans[max_n] = {0};
    int len = 0;
    int temp = n;
    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        int temp = strlen(name);
        if (temp  < len) continue;
        len = temp;
    }
    printf("%s\n", ans);
    return 0;
}

