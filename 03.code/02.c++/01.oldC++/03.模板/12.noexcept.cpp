#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
using namespace std;

const char* foo() noexcept { // 检测到发出异常后，直接会被CPU干掉，即使外层有catch也捕获不到
    //throw("123");
    return "noexcept";
}

void Process(int v) {
    if (v > 3) {
        throw runtime_error("mumber too big");
    }
}

int main() {

    vector<int> v = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        try {
            Process(v[i]);
            cout << v[i] << endl;
        } catch(runtime_error &e) {
            cout << e.what() << endl;
        }
    }


    try {
       cout <<  foo() << endl;//  
    }
    catch(...) {
        cout << "noexcept caught" << endl;
    }

    
    return 0;
}

