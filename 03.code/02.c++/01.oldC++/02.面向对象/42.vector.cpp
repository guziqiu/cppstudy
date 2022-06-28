#include <iostream>
using namespace std;

namespace guziqiu {

class vector {
public :
    vector(int n = 10) : __size(n), data(new int[n]) {
        cout << "default constructor" << endl;
    }
    vector(const vector &v) : __size(v.size()), data(new int[__size]) { //  拷贝构造
        cout << "deep copy constructor" << endl;
        for (int i = 0; i < size(); i++) {
            data[i] = v[i];
        }
        return ;
    }
    vector(vector &&v) : __size(v.size()), data(v.data) { // 移动构造， 传如右值引用构造函数,
        cout << "move copy constructor" << endl;
        v.data = nullptr;
        v.__size = 0;
    }
    vector operator+(const vector &v){ // 合并两个vector
        vector ret(v.size() + this->size());
        vector &now = *this;
        for (int i = 0; i < size(); i++) {
            ret[i] = now[i];
        }
        for (int i = size(); i < ret.size(); i++) {
            ret[i] = v[i - size()];
        }
        return ret;
    }
    int &operator[](int ind) const {
        return this->data[ind];
    }
    int size() const { return __size; }
    ~vector() {
        if (data) delete[] data;
        data = nullptr;
        __size = 0;
    }
private:
    int __size;
    int *data;
};


} // end of guziqiu

ostream &operator<<(ostream &out, const guziqiu::vector &v) {
    for (int i = 0; i < v.size(); i++) {
        out << v[i] << " ";
    }
    out << endl;
    return out;
}



int main() {
    
    guziqiu::vector v1, v2;
    for (int i = 0; i < v1.size(); i++) v1[i] = rand() % 100;
    for (int i = 0; i < v2.size(); i++) v2[i] = rand() % 100;
    
    guziqiu::vector v3(v1 + v2);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;

    guziqiu::vector v4(move(v1)); // 显性的调用移动构造，将v1强制转换成右值引用类型
    cout << "v1 : " << v1 << endl;
    cout << "v4 : " <<v4 << endl;

    return 0;
}

