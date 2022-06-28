/*************************************************************************
    > File Name: 11.x_gcd.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 05 Dec 2020 10:05:58 AM CST
 ************************************************************************/
#include<stdio.h>
int ex_gcd(int a, int b, int *x, int *y) {
	if(!b) {
		*x = 1;
		*y = 0;
		return a;
	}
	int xx;
	int yy;
	int ret = ex_gcd(b, a % b, &xx, &yy);
	*x = yy;
	*y = xx - a / b * yy;
	return ret;
}

int main() {
	int a, b, x, y;

	while (~scanf("%d%d", &a, &b)) {
		printf("ex_gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, &x, &b));
		printf("%d * %d + %d * %d = %d\n", a, x, b, y, (a * x + b * y));
	}
	return 0;
}
