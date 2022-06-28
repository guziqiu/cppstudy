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

struct node {
    int *p;
    int sum;
};

void init(int *root) {
   int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   root = arr;
}

int main() {
    queue<node> que;
    int *root;
   int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   root = arr;
    que.push((node){root, 2});

    while (!que.empty()) {
        cout << *que.front().p << " " << que.front().sum << endl;
        que.pop();
    }


    return 0;
}

