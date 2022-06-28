#include <iostream>
#include <cstdio>
 



int main() {


    long long n, k, sum;
    scanf("%d%d", &n, &k);
    // n = 3, k = 2;
    // n = 556, k = 837;
    int num[10000 + 5] = {0};
    for (int i = 1; i <= n; i++) { 
        num[i] = i;
        //cout << "num[i] = " << num[i] << endl;
    }
    int ans = n;
    int i = 1;
    sum = 1;
    while (ans > 1) {
        //cout << ans << endl;
        if (num[i] > 0) sum++,i++;
        else i++;
        if (i == n + 1) i = 1;
        // cout << "sum = " << sum << ",i = " << i << endl;
        if (sum == k && num[i] != 0) {
            //cout << "==>sum = " << sum << ",i = " << i << endl;
            sum = 1;
            num[i] = 0;
            ans--;
        }
        //if (ans)
    }
    //cout << ans << endl;
    for (i = 1; i <= n; i++) {
        num[i] && printf("%d\n", num[i]);
    }
    //cout << 3 << endl;

    
     
    return 0;
}