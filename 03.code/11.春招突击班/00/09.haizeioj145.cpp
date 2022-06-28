#include <stdio.h>
#include <string.h>
int main() {
    char name[100];
    int n;
    char ans[100];
    scanf("%d", &n);
    for (int i = 0, num = 0, len; i < n; i++) {
        scanf("%s", name);
        len = strlen(name);
        if (num > len) continue;
        num = len;
        strcpy(ans, name);
    }
    printf("%s\n", ans);
    return 0;
}

