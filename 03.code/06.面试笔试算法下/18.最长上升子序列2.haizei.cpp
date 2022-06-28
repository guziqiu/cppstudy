#include <iostream>
#include <cstring>
#define MAX_N 1000000
using namespace std;

int len[MAX_N + 5];//长度为i的序列的最小值
int dp[MAX_N + 5];

int binary_search(int *arr, int n, int x) {//二分查找
    //在arr数组中查找第一个大于等于x的值
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid;
    }
    return head;
}

int main() {

    int n, val;
    int ans = 0;
    scanf("%d", &n);
    memset(len, 0x3f, sizeof(len));//极大值
    len[0] = 0;//极小值，0的位置为极小值，其他位置为极大值
   // for (int i = 0; i < n; i++) scanf("%d", val[i]);
    for (int i = 1; i <= n; i++) {
        cin >> val;
        dp[i] = binary_search(len, ans + 1,val);//找到第一个>=val[i]的值
        len[dp[i]] = val;
        ans = max(dp[i], ans);//最后一位有记录的下标
    }

    cout << ans << endl;

    return 0;
}

