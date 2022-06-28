#include <stdio.h>

int main()
{
    int n;
    int m;
    scanf("%d%d", &n, &m);
    //n行m列
    double stu[40][40] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &stu[i][j]);
            stu[i][n] += stu[i][j];
        }
    }

    for (int i = 0; i < m; i++) 
        printf("%.1f", stu[i][n]);
    return 0;
}

