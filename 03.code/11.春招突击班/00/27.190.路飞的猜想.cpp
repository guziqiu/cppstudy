#include <iostream>
#include <cstdio>

#define MAX_N 8000000

int prime[MAX_N + 5];
int arr[MAX_N + 5];

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!arr[i]) arr[++arr[0]] = i;
        for (int j = i * 2; j <= MAX_N; j += i) {
            arr[j] = 1;
        }
    }
}
// void init() {
//     for (int i = 2; i <= MAX_N; i++) {
// 		if (!prime[i]) prime[++prime[0]] = i;
//     //如果没有值，给他前面一个合数赋值
// 		for (int j = 1; j <= prime[0]; j++) {
// 			if (prime[j] * i > MAX_N) break;
// 			prime[prime[j] * i] = 1;
// 			if (i % prime[j] == 0) break;
// 		}
// 	}

// }

int main() {
    init();
    int n;
    scanf("%d", &n);
    int sum = 0;

    for (int i = 2; i <= n / 2; i++) {
        !prime[i] && !prime[n - i] && sum++;
    } // 别人的代码

    // for (int i = 1; i < n / 2; i++) {
    //     if (prime[i] == 0) continue;
    //     for (int j = 1; prime[j] < n; j++) {
    //         if (prime[i] + prime[j] != n) continue;
    //         prime[i] = prime[j] = 0;
    //         sum++;
    //     }
    // } // 我的代码

    printf("%d\n", sum);



    return 0;
}
