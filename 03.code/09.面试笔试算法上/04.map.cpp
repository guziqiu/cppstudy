#include <iostream>
#include <map>
#include <string>
using namespace std;
#include <unordered_map>

struct Node {
    int x, y;
    bool operator< (const Node &b) const {
        return this->x > b.x;
    }
};


int main() {
    cout << "map<string, int>" << endl;
    map<string, int> m;
    string a = "123";
    m[a] = 999;
    cout << m[a] << endl;
    cout << m["123"] << endl;
    cout << m["456"] << endl;

    cout << "map<Node, int> " << endl;
    map<Node, int> map1;
    Node node;
    map1[node] = 5;

    cout << "unordered_map<string, int>" << endl;
    map<string, int> map2;
    string a2 = "123";
    map2[a2] = 999;
    cout << map2[a2] << endl;
    cout << map2["123"] << endl;
    cout << map2["456"] << endl;

    return 0;
}

