#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

int main() {

    try {
        throw(string("123"));
    } catch(string s) {
        cout << "exception caught" << endl;
    }

    int x;


    return 0;
}

