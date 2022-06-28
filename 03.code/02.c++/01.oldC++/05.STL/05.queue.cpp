#include <iostream>
#include <queue>
using namespace std;

// queue 容器 队列容器 先进先出

void test() {
    queue<int> q, q2(q);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "back : " << q.back() << endl;

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    cout << "size : " <<  q.size() << endl;


}

int main() {
    test();

    return 0;
}
