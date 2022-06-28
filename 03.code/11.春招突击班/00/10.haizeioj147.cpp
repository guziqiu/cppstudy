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
    string num;
    cin >> num;
    
    cout << (num[num.size() - 1] & 1 ? "No" : "Yes") << endl;
    
    return 0;
}

