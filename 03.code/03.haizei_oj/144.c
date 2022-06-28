#include <stdio.h>

int main()
{
    char str[100];

    scanf("%s", str);
    int i = 0;
    int sum = 0;
    while(str[i]) {
        if(str[i] == 'A') sum++;
        i++;
    }
    printf("%d\n", sum);
    return 0;
}

