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
    
    vector<string> stu;

    for (int i = 0; i < 10; i++) {
        string temp;
        cin >> temp;
        stu.push_back(temp);
    }
    sort(stu.begin(), stu.end());
    for (int i = 0; i < 10; i++) {
        cout << stu[i] << endl;
    }
    



    return 0;
}

