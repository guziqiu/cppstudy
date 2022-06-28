#include <iostream>
using namespace std;

class Animal {
public :
    string name() {
        return this->__name;
    }
private :
    string __name;
};

class Cat : public Animal {}; 

int main() {
    
    return 0;
}

