#include <iostream>
#include <memory>
using namespace std;

namespace haizei {

class A {
public :
    A() { 
        cout << "dfault constructor" << endl;
    }
    int x, y;
    ~A() {
        cout << "destructor" << endl;
    }
};

class my_shared_ptr {
public :
    my_shared_ptr();
    my_shared_ptr(A *);
    my_shared_ptr(const my_shared_ptr &);
    int use_count();
    A *operator->();
    A &operator*();
    my_shared_ptr &operator=(const my_shared_ptr &);
    ~my_shared_ptr();
private :
    void decrease_by_one();
    void increase_by_one();
    int *cnt;
    A *obj;
};
my_shared_ptr::my_shared_ptr() : obj(nullptr), cnt(nullptr) {}
my_shared_ptr::my_shared_ptr(A *obj) : obj(obj), cnt(new int(1)) {}

my_shared_ptr::my_shared_ptr(const my_shared_ptr &p) : obj(p.obj), cnt(p.cnt) { 
    increase_by_one(); //*p.cnt += 1; 
}

int my_shared_ptr::use_count(){
    return cnt ? *cnt : 0;
}

A *my_shared_ptr::operator->() {
    return obj;
}

A &my_shared_ptr::operator*() {
    return *obj;
}
my_shared_ptr::~my_shared_ptr() {
    this->decrease_by_one();
    this->obj = nullptr;
    this->cnt = nullptr;
}

void my_shared_ptr::decrease_by_one() { //引用计数-1
    if (this->cnt != nullptr) {
        *(this->cnt) -= 1;
        if (*(this->cnt) == 0) {
            delete this->obj;
            delete this->cnt;
        }
    }
    return ;
}
void my_shared_ptr::increase_by_one() { //引用计数+1
    if (this->cnt != nullptr) {
        *(this->cnt) += 1;
    }
    return ;
}



my_shared_ptr &my_shared_ptr::operator=(const my_shared_ptr &p) {
    if (this->obj != p.obj) {
        decrease_by_one();
        this->obj = p.obj;
        this->cnt = p.cnt;
        increase_by_one();
    }
    return *this;
}

} // end of haizei

using namespace haizei;
int main() {
    
    cout << "p1" << endl;
    A *p1 = new A();
    p1 = nullptr;

    cout << endl << "p2" << endl;
    my_shared_ptr p2(new A());
    cout << p2.use_count() << endl; // 1
    my_shared_ptr p3 = p2;
    p2->x = 123;
    p2->y = 456;
    (*p2).x = 456;
    cout << p3.use_count() << endl; // 2
    p2 = nullptr; // 自动析构
    cout << p3.use_count() << endl; // 1, p2指向了其他对象

    p2 = p3;
    cout << p2.use_count() << endl;




    return 0;
}

