#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;


int main() {
    int n;
    vector<int> stu;
    scanf("%d", &n);
    for (int i = 1, temp; i <= n; i++) {
        scanf("%d", &temp);
        stu.push_back(temp);
    }
    sort(stu.begin(), stu.end());
    for (int i = 0; i < n; i++) {
       printf("%d\n", stu[i]);
    }
    


    return 0;
}
