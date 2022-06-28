#include <iostream>
#include <vector>
#include <cstdio>
#define MAX_N 1000000

long long func(long long *arr, int n, int h) {
    std::vector<long long> v(4, 0);
        //cout << "..." << endl;
    for (int i = 1; i <= n; i++) {
        if (v.size() == 0 && arr[i] <= h) {
            v.push_back(i);
          //  cout << arr[i] << " size = 0,";
        } else if (arr[i] > h) {
            v.clear();
            //cout << "clear ..." << endl;
        } else {
            v.push_back(i);
            //cout << arr[i] << " else ..";
        } 
        if (v.size() >= 3) break;
    }
    //cout << endl;
    return v.front();
}


long long arr[MAX_N + 5];



int main() {
    int n, m, h;
    //cin >> n >> m >> h;
    scanf("%d %d %d", &n, &m, &h);
    for (int i = 1; i <= n; i++) {
        //cin >> arr[i];
        scanf("%lld", &(arr[i]));
    }
    //cout << func(arr, n, h) << endl;
    printf("%lld\n", func(arr, n, h));
    return 0;
}

