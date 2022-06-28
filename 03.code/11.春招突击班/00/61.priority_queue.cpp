#include <iostream>
#include <queue>
 
using namespace std;

struct node {
    int cnt, num;
    bool operator<(const node &b) const{
        return this->num > b.num;
    }
};




int main() {

    // 默认大顶堆，  
    // priority_queue<int, vector<int>, greater<int> > que; //小顶堆

     priority_queue<node> que;
     que.push((node){1, 10});
     que.push((node){2, 20});
     que.push((node){3, 30});


    // que.push(5);
    // que.push(7);
    // que.push(20);
    // cout << que.size() << endl;
    // cout << que.top() << endl << endl;

    while (!que.empty()) {
        cout << que.top().cnt << " " << que.top().num << endl;
        que.pop();
    }


    return 0;
}
