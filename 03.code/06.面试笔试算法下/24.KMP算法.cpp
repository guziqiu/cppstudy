#include <iostream>
#include <cstring>
using namespace std;

int brute_force(const char *s, const char *t) {
    for (int i = 0; s[i]; i++) {
        int flag = 1;
        for (int j =0; t[j]; j++) {
            if (s[i + j] && s[i + j] == t[j]) continue;
            flag = 0;
            break;
        }
        if (flag == 1) return i;
    }
    return -1;
}

void getNext(const char *t, int *next) {
    next[0] = -1;
    int j = -1;//指向上一位next数组的值
    for (int i = 1; t[i]; i++) {
        while (j != -1 && t[j + 1] != t[i]) {
            printf("j = %d , next[j] = %d ", j, next[j]);
            j = next[j];//字符串j+1位!=当前位置
            printf(" j = next[j] = %d, \n", j);
        }
        if (t[j + 1] == t[i]) j += 1;
        next[i] = j;
        printf("next[%d] = %d \n", i, next[i]);
    }
    return ;
}

int kmp(const char *s, const char *t) {
    //初始化next数组
    int n = strlen(t);
    int *next = (int *)malloc(sizeof(int) * n + 1);
    getNext(t, next);
    //输出next数组的值
    /**/
    for (int i = 0; i < n; i++) {
        printf("%d ", next[i]);
    }
    cout << endl;
    /**/
    //使用next数组进行匹配
    for (int i = 0, j = -1; s[i]; i++) {
        while (j != -1 && s[i] - t[j + 1]) j = next[j];
        if (s[i] == t[j + 1]) j += 1;
        if (t[j + 1] == 0) return i - n + 1;
    }
    free(next);
    return -1;
}

int sunday(const char *s, const char *t) {
    int offset[256];
    int n = strlen(t), m = strlen(s);
    for (int i = 0; i < 256; i++) offset[i] = n + 1;//假如所有字符都没没有出现过，
    for (int i = 0; t[i]; i++) offset[t[i]] = n - i;//遍历t字符串,
    for (int i = 0; i + n <= m; i += offset[s[i + n]]) {
        int flag = 1;
        for (int j = 0; t[j] && flag; j++) {
            flag = flag && (s[i + j] == t[j]);
        }
        if (flag) return i;
    }
    return -1;
}


int main() {
    char s[100], t[100];
    while (scanf("%s%s", s, t) != EOF) {
        printf("brute_force(%s, %s) = %d\n", s, t, brute_force(s, t));
        printf("kmp(%s, %s) = %d\n", s, t, kmp(s, t));
        //printf("sunday(%s, %s) = %d\n", s, t, sunday(s, t));
    }

    return 0;
}

