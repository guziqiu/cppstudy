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
    string str = "1234567";
    cout << str.size() << " " << str.length() << endl;

    cout << (int)str.find('6', 6) << endl;

    str = str.insert(1, "abc");
    cout << str << endl;
    str = str.replace(5, 3, "xyz");
    cout << str << endl;
    str = str.substr(5, 5);
    cout << str << endl;


    return 0;
}

