#include <iostream>
using namespace std;
class A{
public:
     A(){cout<<"A::constructor"<<endl;};
     ~A(){cout<<"A::deconstructor"<<endl;};
};
class B{
public:
     B(){cout<<"B::constructor"<<endl;};
     ~B(){cout<<"B::deconstructor"<<endl;};
};
class C : public A{
public:
     C(){cout<<"C::constructor"<<endl;};
     ~C(){cout<<"C::deconstructor"<<endl;};
private:
//    static B b;
     B b;
};
class D : public C{
public:
     D(){cout<<"D::constructor"<<endl;};
     ~D(){cout<<"D::deconstructor"<<endl;};
};

int main(void){
    C* pd = new D();
    delete pd;
    return 0;
}

