#include <iostream>
using namespace std;
#define MAX_N 1000
#define MOD_NUM 100007
int stack[MAX_N + 5], top;
int c[MAX_N + 5][MAX_N + 5];//c[i][j]从[i,j]向上数，有多少个连续的白色格子，即矩形高
int f[MAX_N + 5];//
int n, m;

void read() {
    cin >> n >> m;//第一行输入两个数字 𝑛,𝑚（2≤𝑛,𝑚≤1000），代表矩形的长和宽。
    //接下来 𝑛 行，每行 𝑚 个数字，0 代表黑色格子，1 代表白色格子。
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 1) c[i][j] += c[i - 1][j];
        }
    }
    return ;
}

int solve() {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {//n行
        top = -1;
        stack[++top] = 0;
        c[i][0] = -1;
        f[0] = 0;
        for (int j = 1; j <= m; j++) {//每行m个数字
            while(top != -1 && c[i][stack[top]] > c[i][j]) --top;//出栈，找到第一个比c[i][j]矮的
            f[j] = c[i][j] * (j - stack[top]) + f[stack[top]];//子矩形个数=矩形高x宽(即f(i)右边的子矩形个数) + f(i)左边的子矩形个数
            //cout << "f[j]" << j << " " << f[j] << endl;
            stack[++top] = j;
            f[j] %= MOD_NUM;
            ans += f[j];
            ans %= MOD_NUM;
        }
    }
    return ans;
}


int main() {
    read();
    cout << solve() << endl;



    return 0;
}

