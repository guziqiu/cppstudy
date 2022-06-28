#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v(10, 8);
    for (int i = 20; i > 0; i--) {
        v.push_back(i);
        cout << v.size() << " " << v.capacity() << endl;
    }
    for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
    return 0;
}

