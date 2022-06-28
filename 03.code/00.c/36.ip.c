#include <stdio.h>

union IP {
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    } ip;
    unsigned int num;
};


int main()
{
    union IP p;
    char str[100] = {0};
    int arr[4];
    while (~scanf("%s", str)) {
        sscanf(str, "%d.%d.%d.%d", arr, arr + 1, arr + 2, arr + 3);
        p.ip.a1 = arr[3];
        p.ip.a2 = arr[2];
        p.ip.a3 = arr[1];
        p.ip.a4 = arr[0];
        printf("%u\n", p.num);
        printf("p.ip.a1 %u, a2: %u, a3: %u, a4: %u\n", p.ip.a1, p.ip.a2, p.ip.a3, p.ip.a4);
        printf("arr[0] = %d, arr[1] = %d, arr[2] = %d, arr[3] = %d\n", arr[0], arr[1], arr[2],arr[3]);
        p.ip.a1 = 0;
        p.ip.a2 = 0;
        p.ip.a3 = 0;
        p.ip.a4 = 192;
        printf("%u\n", p.num);
    }
    return 0;
}

