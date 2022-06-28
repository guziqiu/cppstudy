#include <stdio.h>

int main()
{
    int x;
    int y, m, d;
    int date[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%d", &x);
    scanf("%d%d%d", &y, &m, &d);
    if ((y % 4 && y % 100) || y % 400) date[2] = 29;
    int temp;
    temp = date[m] - d;
    temp = x - temp;
    m += 1;
    if (m == 13) {
        y += 1;
        m = 1;
    }
    d = 0;

    while(temp / date[m]) {
        if ((y % 4 && y % 100) || y % 400) date[2] = 29;
        else date[2] = 28;

        if (temp / date[m]){
            m++;

        } 
        if(m > 12) {
            m = 1;
            y += 1;
        }
    }

    temp = temp % date[m];
    d += temp;
    printf("%d%d%d\n", y, m, d);

    

    return 0;
}

