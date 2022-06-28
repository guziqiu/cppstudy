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

#define MAX_N 100000

int prime[MAX_N + 5] = {0};

// 素数
int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void init() { // 素数筛：标记合数
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue; // 是合数
        prime[++prime[0]] = i;
        for (int j = i * i; j <= MAX_N; j+= i) {  // i不能超过10万
            prime[j] = 1; // 合数标记为1
        }
    }
}

void init1() { // 素数筛：标记合数
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i; // 是素数
        for (int j = i; j <= MAX_N / i; j++) {
            prime[i * j] = 1; // 合数标记为1
        }
    }
}

void init2() { // 线性筛：标记合数
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i; // 是素数, 存到数组
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1; // 合数标记为1
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}







int main() {

    int n;
    init1();
    //cin >> n;
    for (int i = 2, j = 1; i <= MAX_N; i++) {
        if (!is_prime(i)) continue;
        //cout << "prime[i] = " << prime[j++];
        cout << "prime[i] = " << prime[j++];
        cout << " , i = " << i  << endl;
    }



    return 0;
}

