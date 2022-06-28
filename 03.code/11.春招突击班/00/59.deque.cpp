#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> que;

    que.push_back(5);
    que.push_back(9);
    que.push_front(-9);

    cout << que.size() << endl;
    cout << que.front() << " " << que.back() << endl << endl;;

    while (!que.empty()) {
        cout << que.back() << endl;
        que.pop_back();
    }


    return 0;
}

