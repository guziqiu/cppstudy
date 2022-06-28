#include <stdio.h>

int main() {
    char a[100];
    scanf("%s", a);

    int  temp = 0;
    while(a[temp]) {
        temp++;
    }
    
    for (int i = temp; i >= 0; i--) {
        printf("%c", a[i]);
    }

    return 0;
}

