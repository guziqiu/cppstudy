#include <iostream>
using namespace std;
int brute_force(const char *s, const char *t) {//暴力匹配算法
    for (int i = 0; s[i]; i++) {
        int flag = 1;
        for (int j = 0; t[j] && flag; j++) {
            flag = flag && (s[i + j] && s[i + j] == t[j]);
        }
        if (flag == 1) return i;
    }
    return -1;
}

int shift_and(const char *s, const char *t) {
    int d[256] = {0}, n = 0;//处理模式串
    for (int i = 0; t[i]; n++,i++) d[t[i]] |= (1 << i);
    int p = 0;
    for (int i = 0; s[i]; i++) {
        p = (p << 1 | 1) & d[s[i]];
        if (p & (1 << (n - 1))) return i - n + 1;//判断p的第n位是否为1，是：完全匹配成功
    }
    return -1;
}

int main() {
    char s[100], t[100];
    while (scanf("%s%s", s, t) != EOF) {
        printf("brute_force(%s, %s) = %d\n", s, t, brute_force(s, t));
        printf("shitf_and(%s, %s) = %d\n", s, t, shift_and(s, t));
    }


    return 0;
}

