#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int prime[10005];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &prime[i]);
    }

    
    for (int i = 2; i <= n; i++) {
        int a = 0;
        int b = 0;
        for (int j = 1; j <= n; j++) {
            //排在他前面且比他高的人数与排在他后面且比他高的人数相等。
            if (j < i && a > prime[i]) a++;
            if (j > i && a > prime[i]) b++;
        }
        if (a == b) printf("==>%d\n", i);
    }
/*
4
1
2
1
3
==>2
==>3
==>4
*/

    return 0;
}

