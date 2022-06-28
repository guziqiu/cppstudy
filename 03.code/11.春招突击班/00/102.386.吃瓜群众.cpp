#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

#define MAX_N 100000

int main() {

    long long m, n;
    map<long long, long long> ma;
    scanf("%lld%lld", &m, &n);

    for (long long i = 1, t; i <= m; i++) {
        scanf("%lld", &t); // X
        ma[t] = i;
    }

    for (long long i = 1, t; i <= n; i++) {
        scanf("%lld", &t); // Y
        printf("%lld\n", ma[t]);
    }

    

    
    return 0;
}

