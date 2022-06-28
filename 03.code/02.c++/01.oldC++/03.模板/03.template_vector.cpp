#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    A() = delete;
    A(int x) : x(x) {}
    friend ostream &operator<<(ostream &, const A &);
private :
    int x;
};

ostream &operator<<(ostream &out, const A &a) {
    out << "Class A :" << a.x << " ";
    return out;
}

namespace guziqiu {
template<typename T>
class vector {
public : 
    vector(int n = 10);
    vector(const vector<T> &);
    vector(vector<T> &);
    T &operator[](int);
    const T &operator[](int) const;
    int size() const;
    void push_back(const T &);
    void push_back(T &&);
    ~vector();
private :
    int __capacity;
    int __size;
    T *data;
};

template<typename T>
vector<T>::vector(int n) : __capacity(n), __size(0), data(nullptr) { // bug 1 data(new T[__size]) 如果T类没有默认构造函数会报错，
    data = (T *)malloc(sizeof(T) * __capacity);
    return ;
}

template<typename T>
vector<T>::vector(const vector<T> &v) : __size(v.size), __capacity(v.__capacity) { // 深拷贝
    //__size = v.__size;
    data = (T *)malloc(sizeof(T) * __capacity);
    for (int i = 0; i < __size; i++) {
        new(data + i) T(v.data[i]); // 原地构造
        //data[i] = v.data[i];  data[i]的存储区可能没有被构造
    }
    return ;
}

template<typename T>
vector<T>::vector(vector<T> &v) : __size(v.__size), data(v.data), __capacity(v.__capacity) { // 移动构造
    v.data = nullptr;
    v.__size = 0;
    v.__capacity = 0;
}

template<typename T>
T &vector<T>::operator[](int ind) {
    return data[ind];
}

template<typename T>
const T &vector<T>::operator[](int ind) const {
    return data[ind];
}

template<typename T>
int vector<T>::size() const { return __size; }

template<typename T>
void vector<T>::push_back(const T &d) {
   new(data + __size) T(d); // 调用相关类型的拷贝构造
   __size += 1;
   return ;
}
template<typename  T>
void vector<T>::push_back(T &&d) {
    new(data + __size) T(move(d)); // 调用相关类型的移动构造
    __size += 1;
    return ;
}

template<typename T>
vector<T>::~vector() {
    if (data) free(data);
    __size == 0;
    __capacity = 0;
    return ;
}

} // end of guziqiu

ostream &operator<<(ostream &out, const vector<A> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return out;
}

ostream &operator<<(ostream &out, const guziqiu::vector<A> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return out;
}


int main() {
    A a(1);
    cout << "vector :" << endl;
    //const vector<A> v;
    vector<A> v;
    //v.push_back(a);
    cout << v.size() << endl;
    v.push_back(123);
    v.push_back(456);
    v.push_back(789);
    cout << v << endl;
    cout << endl << "my vector :" << endl;
    //const guziqiu::vector<A> v2;
    guziqiu::vector<A> v2;
    cout << v2.size() << endl;
    v2.push_back(123);
    v2.push_back(456);
    v2.push_back(789);
    cout << v2 << endl;


    return 0;
}

