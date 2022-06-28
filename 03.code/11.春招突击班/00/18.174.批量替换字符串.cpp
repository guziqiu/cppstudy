#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
#define max_n 1000000

int main() {
    char str[max_n + 5];
    scanf("%[^\n]s", str);

    char ans[max_n + 5];
    unsigned int k = 0;
    for (unsigned int i = 0; str[i]; i++) {
        ans[k] = str[i];
        ans[k + 1] = '\0';
        if (str[i] != ' ') continue;
        ans[k] = '%';
        ans[k + 1] = '2';
        ans[k + 2] = '0';
        ans[k + 3] = '\0';
        k = k + 3;
        printf("ans = %s, str = %s \n", ans, str);
    }
    printf("%s\n", ans);
    
    return 0;
}

