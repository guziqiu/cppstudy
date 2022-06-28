#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int you = 0, liang = 0, zhong = 0, cha = 0;
	int i;
    while(~scanf("%d", &i)) {
        if (i < 60) cha++;
        else if(i <= 79) zhong++;
        else if(i <= 89) liang++;
        else you++;
		n--;
		if(n == 0) break;
    }
    printf("You %d\n", you);
    printf("Liang %d\n", liang);
    printf("Zhong %d\n", zhong);
    printf("Cha %d\n", cha);

    return 0;
}
