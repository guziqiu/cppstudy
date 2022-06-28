#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int x, y;
    double z;
    bool operator< (const Node &b) const{//重载<,默认使用重载小于号，但是小于号内部可以实现各种各样符合需求的功能
        return this->x < b.x;//按照x从大到小
        //return this->x > b.x;//从大到小
    }
};


int main() {
    //自定义结构
    cout << "priority_queue<Node>" << endl;
    priority_queue<Node> que1;
    que1.push((Node){1, 2, 4.5});
    que1.push((Node){2, 1, 5.6});
    cout << que1.top().x << endl;
    que1.pop();
    cout << que1.top().x << endl;
   
    
    cout << "priority_queue<int>" << endl;
    priority_queue<int> que;
    que.push(10);
    que.push(20);
    que.push(5);
    que.push(6);
    que.push(1);
    que.push(18);
    while (!que.empty()) {
        cout << que.top() << endl;
        que.pop();
    }



    return 0;
}

