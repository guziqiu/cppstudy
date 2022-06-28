#include <stdio.h>

//#define DEBUG
#ifdef DEBUG
#define log(frm ,args...) {\
    printf("%s ==> %s : %d]", __FILE__, __func__, __LINE__);\
    printf(frm, ##args);\
}
#else 
#define log(frm, args...)
#endif

//#args将args(任意类型都可)转换为字符串
//如果lon传入的参数为1个，变参列表就为空，编译器会报警告，too manny argument..
//##args连接，如将a和b连接为ab，连接时后面的可以为空

//#define concat(a, b) a##b
//如果去掉##，写ab的意思是将a、b变量替换成字符ab

int main()
{

    int a = 123;
    printf("printf==>hello 古子秋\n");
    log("log==>hello apricity\n");
    log("lon(a)==>%d\n", a);
    int abc = 2;
    int def = 3;
    int abcdef = 0;
//    concat(abc, def) = 234;
    log("abcdef = %d\n", abcdef);
    
    return 0;
}

