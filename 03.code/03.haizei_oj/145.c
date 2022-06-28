#include <stdio.h>
#include <string.h>
#define max_n 150
int main()
{
    int n;
    char name[20][max_n] = {0};
    int temp = n;
    for (int i = 0; i < n; i++) {
        scanf("%s", name[i]);
    }
    int index = 0;
    int len = 0;
    for (int i = 0; i < n; i++) {
        int temp  = strlen(name[i]);
        if (temp < len) continue;
        len = temp;
        index = i;
    }
    printf("%s\n", name[index]);
    return 0;
}

