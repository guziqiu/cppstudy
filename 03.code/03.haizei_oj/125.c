#include <stdio.h>
int main() {
    int h, m, s, t;
    scanf("%d%d%d%d", &h, &m, &s, &t);
    int temp;
    temp = h * 3600 + m * 60 + s + t;
    int h1, m1, s1;
    h1 = temp / 3600;
    m1 = temp % 3600 / 60;
    s1 = temp % 60;
    int i = 0;
    while(h1 >= 24) {
        h1 -= 24;
    }
    if (h1 > 12) {
        h1 -= 12;
        i = 1;
    }
    if (h1 == 12 && i == 0) i = 1;
	if (h1 == 0) i = 0;
    printf("%d:%d:%d%s\n", (h1 == 0) ? 12:h1 , m1, s1, (i == 1) ? "pm": "am");

    double time = (double)t / (24 * 60 * 60) * 100;
    printf("%.2f%%\n", time);

        return 0;
}
