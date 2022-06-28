#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}
int arr[MAX_N + 5][MAX_N + 5];

void func(int r1,int r2,int c1,int c2,int s,int A) {
    // r行c列，， 排序依据s列,,A == 0,小到大，A==1从大到小
    /*
    cout << "func " << endl;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    */
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j < c2; j++) {
            if (arr[i][j] > arr[i][j + 1] && A == 1) swap(arr[i][j], arr[i][j + 1]);
            if (A == 0 && arr[i][j] < arr[i][j + 1]) swap(arr[i][j], arr[i][j + 1]);
        }
    }
    for (int i = c1; i <= c2; i++) {
        for (int j = r1; j < r2; j++) {
            if (A == 1 && arr[j][i] < arr[j + 1][i]) swap(arr[j][i], arr[j + 1][i]);
            if (A == 0 && arr[j][i] > arr[j + 1][i]) swap(arr[j][i], arr[j + 1][i]);
        }
    }



    /*
    vector<int> v;
    for (int i = c1; i <= c2; i++) {
        cout << "push back : "  << endl;
        int num = 0;
        for (int j = r1; j <= r2; j++) {
            v.push_back(arr[j][i]);
            cout << v[num] << " ";
            num++;
        }
        cout << endl;
        sort(v.begin(), v.end());
        if (A == 1) {
            //cout << endl;
            for (int j = r1; j <= r2; j++) {
                //cout << "num" << num << " num ";
                arr[j][i] = v[--num];
                cout << "a == 1 ," << v[0] << " " << v[1] << endl;
                //cout << " = " <<  arr[j][i] << " ";
            }
            // cout << endl;
        } else {
            cout << "a == 0, " << endl;
            int t = 0;
            for (int j = r1; j <= r2; j++) {
                arr[j][i] = v[t++];
                //cout << "a == 1 ," << v[0] << " " << v[1] << endl;
            }
        }
        v.clear();
    }   
    */
   return ;
}

int main() {
    int n, m, t;
    
    cin >> n >> m >> t; // n * m 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < t; i++) {
        int r1, r2, c1, c2, s, A; // r行c列，， 排序依据s列,,A == 0,小到大，A==1从大到小
        cin >> r1 >> r2 >> c1 >> c2 >> s >> A;
        func(r1, r2, c1, c2, s, A);
    }
    //cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            (j - 1) && cout << " ";
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}

