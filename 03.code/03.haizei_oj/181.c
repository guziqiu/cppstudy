#include <stdio.h>

int main()
{
     char a[1000];
    scanf("%s", a);
    char b = a[0];
    for (int i = 0; a[i] != '\0' ; i++){
        //b = a[i];
        if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 32; 
        else  a[i] += 32;
    }
    printf("%s\n", a);
    return 0;
}

