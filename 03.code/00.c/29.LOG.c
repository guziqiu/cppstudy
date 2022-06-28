#include <stdio.h>
#define log(frm, args...) {\
    printf("[%s -> %s : %d]", __FILE__, __func__, __LINE__);\
    printf(frm, ##args);\
}

#define contact(a, b) a##b

//##连接字符串a，b为ab
int main()
{
    int a;
    printf("[%s : %d]" " hello guziqiu",__func__,  __LINE__);
    printf("[%s : %d] %d\n", __func__, __LINE__, a);
    
    int b;
    printf("= = >\n");
    log("= = >\n");
    log("%d\n", a);



    return 0;
}

