#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> mergePrice(int* a, int aLen, int* b, int bLen) {
        // write code here
    vector<int> ret;
    for (int i = 0; i < aLen; i++) {
        ret.push_back(a[i]);
    }
    for (int i = 0; i < bLen; i++) {
        ret.push_back(b[i]);
    }
    sort(ret.begin(), ret.end());
    return ret;
}
int main() {
    
    return 0;
}

