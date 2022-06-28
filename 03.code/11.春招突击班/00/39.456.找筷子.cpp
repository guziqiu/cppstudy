#include <iostream>
#include <cmath>
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
#define MAX_N 1000000 

int arr[MAX_N + 5] = {0};

int main() {
    int n;
    vector<int> num;
    scanf("%d", &n);

    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        if (num[i] == num[i + 1] && num[i] != 0) {
            num[i] = num[i + 1] =0;
        }
    }
    for (int i = 0; i <= num.size(); i++) {
        num[i] != 0 && cout << num[i] << endl;
    }




    // int n;
    // vector<int> num;
    // // queue<int> q;
    // cin >> n;

    // for (int i = 0, temp; i < n; i++) {
    //     cin >> temp;
    //     num.push_back(temp);
    // }
    // sort(num.begin(), num.end());

    // q.push(num[0]);
    // for (int i = 1; i < n; i++) {
    //     // printf("num[%d] = %d\n", i, num[i]);
    //     if (num[i] == q.front()) {
    //         q.pop();
    //         // cout << "q.pop : " << num[i] << endl;
            
    //     }
    //     else {
    //         q.push(num[i]);
    //         // cout << "q.push : " << num[i] << endl;
    //     } 
    // }
    // cout << q.front() <<endl;


    return 0;
}
