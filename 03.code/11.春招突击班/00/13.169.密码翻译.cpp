
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 26
#define N2 30

int dic[N];
char s[N2 + 1];

int main(void)
{
    int n, a, i;

    memset(dic, 0, sizeof(dic));

    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        scanf("%s", s);
        scanf("%d", &a);
        dic[s[0] - 'A'] = a;
    }

    scanf("%s", s);
    int sum = 0;
    for(i = 0; s[i]; i++)
        if(isupper(s[i]))
            sum += dic[s[i] - 'A'];

    // 输出结果
    printf("%d\n", sum);

    return 0;
}

