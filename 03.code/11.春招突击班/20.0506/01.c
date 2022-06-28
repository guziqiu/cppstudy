#include <stdio.h>

char *getStr(void) {
    char p[] = "123";
    //cout << p << endl;
    return p;
}

void test(void) {
    char *str = NULL;
    //cout << getStr() << endl;
    str = getStr();
    printf("%s\n", str);
   // cout << str << endl;
}

int main() {
    test();
    return 0;
}

