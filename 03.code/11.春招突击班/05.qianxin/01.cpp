#include <iostream>
using namespace std;
#define MAX_N 10000
int prime[MAX_N + 5];
void init() { // 线性筛
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1; // 合数标记为1
            if (i % prime[j] == 0) break;
        }
    }
    //cout << "end" << endl;
    //for (int i = 0; i < prime[0]; i++) cout << prime[i] << endl;
}
long long getMaxVolume(long long n) {
    // write code here
    long long  max = 0;
    init();
    for (int i = 1; prime[i] <= n; i++) {
        for (int j = 1; prime[j] <= n; j++) {
            for (int k = 1; prime[k] <= n; k++) {
                int t = prime[i] * prime[j] * prime[k];
                if (prime[i] + prime[j] + prime[k] == n) max = (max > t ? max : t);
            }
        }
    }
    return max;
}
int main() {
    cout << getMaxVolume(6) << endl;
    return 0;
}
