#include <iostream>
using namespace std;
#define MAX_N 100000
int c[MAX_N + 5];
#define lowbit(x) (x & (-x))

void add(int i, int x, int n) {
    //在c[n]中的c[i]加x
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return ;
}

int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;//原数组前n项和为第i项的值
}

int main() {
    int n, m, pre, a;
    cin >> n;//第一行一个整数𝑁,代表序列𝐴的长度
    //第二行是由空格分隔开的𝑁个数，分别代表𝐴1，𝐴2……𝐴𝑛
    pre = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;//a代表当前输入的值
        add(i, a - pre, n);//pre代表上一个输出的值
        pre = a;
    }
    cin >> m;//接下来一行是一个整数𝑚，代表操作的次数。
    char str[10];
    //接下来𝑚行，每行代表这一条指令如题目所述
    int l, r, d, x;
    for (int i = 0; i < m; i++) {
        cin >> str;
        switch (str[0]) {
        case 'C': {
                      // 第一类指令形如𝐶 𝑙 𝑟 𝑑(1≤𝑙≤𝑟≤𝑁)，表示把数列中第𝑙...𝑟之间的数都加𝑑(0≤𝑑≤100000)
                      cin >> l >> r >> d;
                      add(l, d, n);
                      add(r + 1, -d, n);
                  } break;
        case 'Q': {
                      cin >> x;//第二类指令形如𝑄 𝑥(𝑥≤𝑁)，表示询问序列中第𝑥个数的值。
                      cout << query(x) << endl;
                } break;
        }
    }

    return 0;
}

