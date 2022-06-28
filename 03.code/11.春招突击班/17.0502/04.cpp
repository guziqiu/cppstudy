#include <iostream>
using namespace std;

typedef struct name1{
    char c;
    float x;
} name; 


int main() {

        
    cout << "char : " << sizeof(char) << endl;    
    cout << "char *: " << sizeof(char *) << endl;    
    cout << "short : " << sizeof(short) << endl;    
    cout << "int : " << sizeof(int) << endl;    
    cout << "long long : " << sizeof(long long) << endl;    
    cout << "float : " << sizeof(float) << endl;    
    cout << "double : " << sizeof(double) << endl;    
    cout << "name1 : " << sizeof(name) << endl;



    return 0;
}

