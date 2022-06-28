
#ifndef _TEST_H 
#define _TEST_H

//颜色
#define COLOR(a, b) "\033[" #b "m" a "\033[0m"         //正常颜色
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"    //高亮颜色

#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)

#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)

#define TEST(a, b)\
void a##_haizei_##b();\
__attribute__((constructor))\
void add##_haizei_##a##_haizei_##b() {\
    add_function(a##_haizei_##b, #a "." #b);\
}\
void a##_haizei_##b()//函数的名字是ab,中间加入符号，解决重名的问题 

#define TYPE(a) _Generic((a), \
    int: "%d", \
    double: "%lf", \
    float: "%lf", \
    long long: "%lld", \
    const char*: "%s", \
    char*: "%s")
//TYPE(a)获取a的类型转换成格式占位符

#define P(a, color) {\
    char frm[1000];\
    sprintf(frm, color("%s"), TYPE(a));\
    printf(frm, a);\
}
#define EXPECT(a, b, comp) {\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    haizei_test_info.total += 1;\
    if (_a comp _b) haizei_test_info.sucess += 1;\
    else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s:%d: failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect : " #a " " #comp " " #b "\n\t\t" "actual : "));\
        P(_a, YELLOW_HL);\
        printf(YELLOW_HL(" vs "));\
        P(_b, YELLOW_HL)\
        printf("\n\n");\
    }\
    printf(GREEN("[-----------]"));\
    printf(" %s %s %s ? %s \n", #a, #comp, #b, _a comp _b ? GREEN("TRUE") : RED("FASE"));\
}
// __typeof(a) _a = (a) // 避免add(a++, b)

#define EXPECT_EQ(a, b) EXPECT(a, b, ==) // ==
#define EXPECT_NE(a, b) EXPECT(a, b, !=) // !=
#define EXPECT_LT(a, b) EXPECT(a, b, <)  // <
#define EXPECT_LE(a, b) EXPECT(a, b, <=) // <=
#define EXPECT_GT(a, b) EXPECT(a, b, >)  // >
#define EXPECT_GE(a, b) EXPECT(a, b, >=) // >=

typedef void (*TestFuncT)();//函数指针

typedef struct Function {//将信息打包成结构体
    TestFuncT func;//指向函数
    const char *str;//名字
} Function;

struct FunctionInfo {
    int total;//总测试点信息
    int sucess;//成功通过的总数
};

extern struct FunctionInfo haizei_test_info;//用当前结构体类型定义一个变量,extern 申明一个外部变量
void add_function(TestFuncT, const char *);
int RUN_ALL_TESTS();


#endif

