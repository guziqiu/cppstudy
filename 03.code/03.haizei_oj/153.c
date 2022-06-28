#include <stdio.h>

int main()
{
    int q, m, j, k;
    int year, mouth, day;
    scanf("%d%d%d", &year, &mouth, &day);


    if(mouth == 1) {
        mouth = 13;
        year -= 1;
    }
    if(mouth == 2) {
        mouth = 14;
        year -= 1;
    }
    q = day;
    m = mouth;
    j = year / 100;
    k = year % 100;

    int h = (q + 26 * ( m + 1) / 10 + k + k / 4 + j / 4 + 5 * j) % 7;
    switch(h) {
        case 0: printf("6\n");break;
        case 1: printf("7\n");break;
        case 2: printf("1\n");break;
        case 3: printf("2\n");break;
        case 4: printf("3\n");break;
        case 5: printf("4\n");break;
        case 6: printf("5\n");break;
        default:
                printf("==>error\n");
                break;
    }
    return 0;
}

