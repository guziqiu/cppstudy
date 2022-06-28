#include <stdio.h>

int main()
{
    char a[100];
    scanf("%s", a);
    
    for (int i = 0; a[i] != '\0'; i++) {
        if(a[i] == 'Z') {
            a[i] = 'A';
            continue;
        }
        if(a[i] == 'z'){
            a[i] = 'a';
            continue;
        }
        if((a[i] >= 'a' && a[i] < 'z') || (a[i] >= 'A' && a[i] < 'Z')) a[i] = a[i] + 1;
    }
    printf("%s\n", a);


    return 0;
}

