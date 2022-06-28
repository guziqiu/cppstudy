#include <iostream>
#include <algorithm>
using namespace std;

struct task {
    int t, m;
};

int n, m; 
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

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (game[i].t >= i && sum <= i) {
            sum++;
            continue;
        }
        m -= game[i].m;
    }
    cout << m << endl;
        
    return 0;
}

