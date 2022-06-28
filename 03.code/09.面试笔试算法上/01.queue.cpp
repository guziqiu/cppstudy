#include <iostream>
#include <queue>

using namespace std;
struct Node {
    int x, y;
};

int main() {
    queue<int> que;
    for (int i = 9; i > 4; i--) {
        que.push(i);
    }

    while (!que.empty()) {
        //queue.size();
        cout << "que.front() = " << que.front() << "\t que.size() = " << que.size() << endl;
        que.pop();
    }
    queue<Node> q;
    Node node;
    node.x = 1;
    node.y = 2;
    q.push(node);
    q.push((Node){7, 8});
    cout << q.front().x << endl;//1
    q.pop();
    Node temp = q.front();
    cout << temp.x << " " << temp.y << endl;
    
    return 0;
}

