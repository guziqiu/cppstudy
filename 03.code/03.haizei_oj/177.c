#include <stdio.h>

int main()
{
    char a[30];
    scanf("%s", a);

    for(int i = 0; a[i] != '\0'; i++) {
        for (int j = i; a[j] != '\0'; j++) printf("%c", a[j]);
        printf("\n");
    }
    
    return 0;
}

