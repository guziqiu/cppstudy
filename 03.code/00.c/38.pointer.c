#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define offset(T, a) ({\
    T temp;\
    (char *)(&temp.a) - (char *)(&temp);\
})

#define ppchar char *
typedef char * pchar;

struct Data {
    int a;
    double b;
    char c;
};
//__attribute__((constructor))
void output(int argc, char *argv[], char *env[]) {
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    for (int i = 0; env[i]; i++) {
        if (!strncmp(env[i], "USER=", 5)) {
            if (!strcmp(env[i] + 5, "apricity")) {
                printf("welcome apricity...!\n");
            } else {
              //  printf("you are not the user! please exit\n");
                //exit(0);
            }
        }
        printf("env[%d] = %s\n", i, env[i]);
    }

}

int main(int argc, char *argv[], char *env[]) {
    output(argc, argv, env);
    return 0;

    int num = 0x0626364;
    printf("%s\n", (char *)(&num));

    printf("%ld\n", offset(struct Data, a));
    printf("%ld\n", offset(struct Data, b));
    printf("%ld\n", offset(struct Data, c));

    pchar p1,p2;
    ppchar p3,p4;
    printf("p1 = %lu, p2 = %lu\n", sizeof(p1), sizeof(p2));
    printf("p3 = %lu, p4 = %lu\n", sizeof(p3), sizeof(p4));

    return 0;
}

