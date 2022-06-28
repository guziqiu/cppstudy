#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct UnionSet {
    int *color; // 标记颜色
    int n; // 大小
} UnionSet;

UnionSet *init(int n) { // 并查集初始化
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet)); // 初始化
    u->color = (int *)malloc(sizeof(int) * (n + 1)); // 从1号位开始存储
    u->n = n;
    // 初始化颜色
    for (int i = 1; i <= n; i++) {
        u->color[i] = i;
    }
    return u;
}

int find(UnionSet *u, int x) { // 查找操作，查找x
    return u->color[x]; // 返回当前元素的颜色
}

int merage(UnionSet *u, int a, int b) { // 合并操作, 合并a,b
    if (find(u, a) == find(u, b)) return 0; // a,b本身就有连通关系
    // 染色
    int color_a = u->color[a];
    for (int i = 1; i <= u->n; i++) {
        if (u->color[i] != color_a) continue; // if (u->color[i] - color_a)
        u->color[i] = u->color[b]; // 找到和u->color[a] 一样的颜色
    }
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->color);
    free(u);
    return ;
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        switch (a) {
        case 1:
            merage(u, b, c); break;
        case 2:
            cout << (find(u, b) == find(u, c) ? "Yes" : "No") << endl;
            break;
        }
    }





        
    return 0;
}

