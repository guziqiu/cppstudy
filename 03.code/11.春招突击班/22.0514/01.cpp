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
    short s = 'a';//合法
    unsigned int ui = 200;//合法
    int i = -1000;//合法
    double d = i;//合法
    if( (ui + i) > 0 )
        cout << "(ui +i) > 0" << endl;
    else
        cout << "(ui +i) < 0" << endl;
    return 0;
}

