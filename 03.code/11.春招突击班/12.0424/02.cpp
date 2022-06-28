#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct player {
    int x, y;
} player;
player myself;
player pl[205];
double R;
int timer[10005][10005];
vector<vector<int>> other;
char str[50005];

void judge(int p, int t) { // 判断p在t时是否在视眼内
    // 玩家p在t s时，向str方向移动了s
    int ind = 0;
    if (t > 0) {
    for (int i = 1; i <= timer[t][0]; i++) {
        if (timer[t][i] == p) ind = 1; 
    }
    }
    if ( fabs(pl[p].x - myself.x) <= R && fabs(pl[p].y - myself.y) <= R){ // 进去了
     if (ind == 0) {
            timer[t][0]++;
            timer[t][timer[t][0]] = p;
            return ;
        } 
    } else { 
    //if (fabs(pl[p].x - myself.x) > R || fabs(pl[p].y - myself.y) > R) {
     if (ind == 1) {
         timer[t][0]--;
         return ;
     }
    }

}

int main() {
    int m, n, x, y, r;
    cin >> m >> n >> x >> y >> r;
    myself.x = x;
    myself.y = y;
    int k;
    R = (2 * r + 1) / 2;
    cin >> k; // 其他玩家的数量
    for (int i = 1; i <= k; i++) {
        cin >> pl[i].x >> pl[i].y; // 其他玩家的坐标
        if (fabs(pl[i].x - x) <= R && fabs(pl[i].y - y) <= R) {
            timer[0][0]++;
            timer[0][timer[0][0]] = i;
        }
    }

    int c;
    cin >> c;// 其他玩家的操作数
    for (int i = 0; i < c; i++) {
        int p, t, s;
        cin >> p >> t >> s >> str[i]; // 玩家p在t 时，向str方向移动了s
        other.push_back({t, p, s, i});
    }
    sort(other.begin(), other.end());
    for (int i = 0; i < other.size(); i++) {
        int p, t, s;
        p = other[i][1];
        t = other[i][0];
        s = other[i][2];
        switch (str[other[i][3]]) {
        case 'W': // 上
            
            pl[p].y += s;
            judge(p, t); // 
            break;
        case 'A': // 左
            pl[p].x -= s;
            judge(p, t);
            break; 
        case 'S': // 下
            pl[p].y -= s;
            judge(p, t);
            break;
        case 'D': // 右
            pl[p].x += s;
            judge(p, t);
            break;
        }
        //p[v[i][0]]
    }


    int d;
    cin >> d;
    for (int i = 0; i < d; i++) {
        int op;
        cin >> op;
        i && cout << " ";
        cout << timer[op][0];
    }
    cout << endl;
    




    return 0;
}

