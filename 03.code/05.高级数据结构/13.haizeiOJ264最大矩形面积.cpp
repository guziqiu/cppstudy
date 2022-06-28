#include <iostream>
using namespace std;
#define MAX_N 100000
long long stack[MAX_N + 5];//单调栈，记录下标
long long top;//栈顶指针
long long h[MAX_N + 5];//记录每一块木板的长度
long long n;

long long l[MAX_N + 5],r[MAX_N + 5];//l

void read() {
    //cin >> n;
    scanf("%lld", &n);
    //输入共一行，第一个数表示矩形的个数 𝑁。接下来 𝑁 个数表示矩形的大小。（1≤𝑁≤100000）
    for (long long i = 1; i <= n; i++) scanf("%lld", h + i);
        //cin >> h[i];
    return ;
}

long long solve() {
    h[0] = h[n + 1] = -1;//最边上的两块木板,即边界木板
    top = -1;
    //求最近小于关系，单调递增栈
    //左边木板
    stack[++top] = 0;//0坐标先压栈
    for (long long i = 1; i <= n; i++) {
        while (top != -1 && h[stack[top]] >= h[i]) --top;//出栈
        l[i] = stack[top];//第i块木板左边离他最近的且高度小于他的木板编号
        stack[++top] = i;//入栈

    }
    //右边木板
    top = -1;//清空栈
    //求最近小于关系，单调递增栈
    stack[++top] = n + 1;//最右边坐标先压栈
    for (long long i = n; i >= 1; i--) {
        while (top != -1 && h[stack[top]] >= h[i]) --top;//出栈
        r[i] = stack[top];//第i块木板右边离他最近的且高度小于他的木板编号
        stack[++top] = i;//入栈
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        ans = max(ans, h[i] * (r[i] - l[i] - 1));
    }
    return ans;
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}

