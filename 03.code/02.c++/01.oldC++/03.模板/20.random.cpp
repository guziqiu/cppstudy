#include <iostream>
using namespace std;

namespace guziqiu {
    static int __seed = 3;
    void srand(int seed) {
        __seed = seed;
        return ;
    }
    int rand() {
        return __seed = __seed * 3 % 101;
    }
} // end of guziqiu


int main() {
    guziqiu::srand(time(0));
    for (int i = 0; i < 10; i++) {
        cout << guziqiu::rand() << endl;
    }
    
    return 0;
}

