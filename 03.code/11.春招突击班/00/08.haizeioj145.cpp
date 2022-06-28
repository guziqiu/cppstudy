#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string name;
    string ans;
    int n;
    
    scanf("%d", &n);
    for (int i = 1, num = 0; i <= n; i++) {
        cin >> name;
        if (name.size() < num) continue;
        num = name.size();
        ans = name;
    }
    cout << ans << endl;

    return 0;
}

