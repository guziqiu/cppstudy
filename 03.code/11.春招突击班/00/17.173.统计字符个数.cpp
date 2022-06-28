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
    char str[1000];
    scanf("%[^\n]s", str);
    int a, b, c, d;
    a = b = c = d = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) a++;
        else if (str[i] >= '0' && str[i] <= '9') b++;
        else if (str[i] == ' ') c++;
        else d++;
    }
    printf("%d %d %d %d\n", a, b, c, d);


    return 0;
}

