#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char str[100];
    str[0] = 'A';
    int j = 2 * n + 1;
    for (int i = 1; i <= n + 1; i++) {
        str[i] = str[j--] = str[0]++;
    }

    int k = 2 * n + 1;
    int m;
    for (j = 1; j <= n + 1; j++) {
        for (m = 1; m < j; m++) printf(" ");
        for (int i = j; i <= k; i++)  printf("%c", str[i]);
        k--;
        printf("\n");
    }
    
    k = n + 2;
    for (j = n; j >= 1; j--) {
        for (m = 1; m < j; m++) printf(" ");
        for (int i = j; i <= k; i++) printf("%c", str[i]);
        k++;
        printf("\n");
    }
    return 0;
}

