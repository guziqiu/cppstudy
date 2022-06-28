#include <stdio.h>
#define MAX_N 1000000
int arr[MAX_N + 5][MAX_N + 5];
int main() {
    int n, m, k;
    //cin >> n >> m >> k;
    int t = scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        int x, y, u, v, w;
        t = scanf("%d %d %d %d %d", &x, &y, &u, &v, &w);
        //cin >> x >> y >> u >> v >> w;
        if (arr[u][v] == 0) arr[u][v] = w;
        else if(arr[u][v] > w && x == 1 && y == 1) arr[u][v] = w;
        else if (arr[u][v] > w) {
            if (arr[x][y] != 0 && ((arr[x][y] + w) < arr[u][v])) arr[u][v] = arr[x][y] + w;
        } else {
            continue;
        }
        //cout << "k" :" << k << endl;
    }
    if (arr[n][m] == 0) printf("-1\n");//cout << -1 << endl;
    else printf("%d\n", arr[n][m]);//cout << arr[n][m] << endl;



    return 0;
}

