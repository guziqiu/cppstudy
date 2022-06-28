#include <iostream>
#include <algorithm>
using namespace std;

struct task {
    int t, m;
};

int n, m, mark[10000] = {1}; // 标记数组，钱对应的数组是否被用过
task game[505];
bool cmp(task a, task b) { // 优先保证完成钱多的任务
    if (a.m == b.m) return a.t < b.t;
    return a.m > b.m;
}
int main() {

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        cin >> game[i].t;
    }

    for (int i = 0; i < n; i++) {
        cin >> game[i].m;
    }

    sort(game, game + n, cmp);

    for (int i = 0; i < n; i++) {
        for (int j = game[i].t; j >= 0; j--) {
            if (mark[j] == 0) {
                mark[j] = 1;
                break;
            }
            if (j == 0) {
                m -= game[i].m;
                cout << game[i].m << ":" << game[i].t << endl;
            }
        }
    }

    cout << m << endl;



        
    return 0;
}

