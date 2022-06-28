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

using namespace std;

int main() {
    char str[100] = {0};
    scanf("%[^\n]s", str);
    printf("%s\n", str);
    
    while (~scanf("%[^\n]s", str)) {
        char a = getchar();//吞掉字符
        printf("a = (%c)\n", a);
        printf("%s\n", str);
    }

    return 0;
}

