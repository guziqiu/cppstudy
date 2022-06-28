#include <iostream>
using namespace std;


namespace guziqiu {
template<typename T>
void swap(T &&a, T &&b) {
    typename remove_reference<T>::type c; // declared as reference but not initialized
    // remove_reference 去掉相关类型的引用, T == T &c  = a;
    c = a;
    a = b;
    b = c;
    return ;
}
} // end of guziqiu


int main() {
    int n = 123, m = 456;
    guziqiu::swap(n, m);
    cout << n << " " << m << endl;
    
    //guziqiu::swap(789, m);
    //cout << n << " " << m << endl;



    return 0;
}

