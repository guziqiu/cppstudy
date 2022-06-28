#include <stdio.h>
#define max_n 100
int main()
{
    int n, m;
    double stu[max_n][max_n] = {0};
    scanf("%d%d", &n, &m);
    //n行m列
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &(stu[i][j]));
            stu[i][m] += stu[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        double temp = stu[i][m] / m;
        printf("%.6lf\n", temp);
    }

    return 0;
}

