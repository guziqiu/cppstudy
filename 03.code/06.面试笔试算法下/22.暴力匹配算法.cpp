#include <iostream>
using namespace std;

int brute_force(const char *s, const char *t) {
    for (int i = 0; s[i]; i++) {
        int flag = 1;
        for (int j =0; t[j]; j++) {
            if (s[i + j] == t[j]) continue;
            flag = 0;
            break;
        }
        if (flag == 1) return i;
    }
    return -1;
}


int main() {
    char s[100], t[100];
    while (scanf("%s%s", s, t) != EOF) {
        printf("match(%s, %s) = %d\n", s, t, brute_force(s, t));
    }

    return 0;
}

