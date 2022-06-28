#include <iostream>
#include <map>
using namespace std;

#define MAX_N 100000000
int attack[MAX_N + 5];
int money[MAX_N + 5];
int ans[MAX_N + 5];
int ma[MAX_N + 5][2];
int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> attack[i];
        m[attack[i]] = i;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> money[i];
    }
    int i = 0;
    ans[0] = 0;
    int t = 0;
    for (auto it = m.begin(); it != m.end(); it++, i++) {
        ma[i][0] = it->first;
        ma[i][1] = it->second;
        //cout << "it->first = " << it->first << " , it->second = " << it->second <<", money[it->second] = " << money[it->second] << endl;
        //ans[it->second] = t + money[it->second];
        //cout << t << endl;
        //t += money[it->second];
        //cout << ans[i] << endl;
        //i++;
    }

    int temp;
    for (int j = n - 1; j >= 0;j--) {
        ans[j] = 0;
        //cout << "j = "<< j <<  ", ma[j][0] = " << ma[j][0] << endl;
        int k = (j - k) > 0 ? (j - k) : 0; 
        for (; k <= j; k++) {
            cout << "k = " << k << " , money[ma[k][1]] = " << money[ma[k][1]] << " ";
            ans[j] += money[ma[k][1]];
        }
        cout << endl;
    }


    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}



