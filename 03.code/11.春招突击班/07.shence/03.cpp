#include <iostream>
#include <vector>
using namespace std;

int m[7] = {1, 2, 5, 10, 20, 50, 100};

int n[7];
vector<vector<int>> v;
int func(int target) {
    for (int a = 0; a <= n[0]; a++) {
        if (m[0] * a == target)v.push_back({a, 0, 0, 0, 0, 0, 0});
    for (int b = 0; b <= n[1]; b++) {
        if (m[0] * a + m[1] * b + m[2] * 0 + m[3] * 0 + m[4] * 0 + m[5] * 0 +  m[6] * 0 == target)v.push_back({a, b, 0, 0, 0, 0, 0});
    for (int c = 0; c <= n[2]; c++) {
        if (m[0] * a + m[1] * b + m[2] * c + m[3] * 0 + m[4] * 0 + m[5] * 0 + m[6] * 0 == target)v.push_back({a, b, c, 0, 0, 0, 0});
    for (int d = 0; d <= n[3]; d++) {
        if (m[0] * a + m[1] * b + m[2] * c + m[3] * d + m[4] * 0 + m[5] * 0 + m[6] * 0 == target)v.push_back({a, b, c, d, 0, 0, 0});
    for (int e = 0; e <= n[4]; e++) {
        if (m[0] * a + m[1] * b + m[2] * c + m[3] * d + m[4] * e + m[5] * 0 + m[6] * 0 == target)v.push_back({a, b, c, d, e, 0, 0});
                    for (int f = 0; f <= n[5]; f++) {
    if (m[0] * a + m[1] * b + m[2] * c + m[3] * d + m[4] * e + m[5] * f + m[6] * 0 == target)v.push_back({a, b, c, d, e, f, 0});
                            for (int g = 0; g <= n[6]; g++) {
                    if (m[0] * a + m[1] * b + m[2] * c + m[3] * d + m[4] * e + m[5] * f + m[6] * g == target)v.push_back({a, b, c, d, e, f, g});
                                
                            }
            }
        }
    }
    }}}
    return 1;
}




int main() {
    int tar;
    for (int i = 0; i < 7; i++) {
        cin >> n[i];
    }

    cin >> tar;

    func(tar);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            j && cout << " ";
            cout << v[i][j];
        }
        cout << endl;
    }

    
    return 0;
}

