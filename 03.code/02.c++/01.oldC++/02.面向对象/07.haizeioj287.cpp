#include <iostream>
#include <queue>
using namespace std;

struct CMP {
public:
    bool operator()(int a, int b) {
        return a > b;
    }//重载优先队列排序规则
};

int main() {
    priority_queue<int, vector<int>, CMP> q;//优先队列
    int n;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        q.push(a);
    }
#if 0
    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
#endif
    int sum = 0;
    for (int i = 1; i < n; i++) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        sum += a + b;
        q.push(a + b);
    }
    cout << sum << endl;

    return 0;
}

