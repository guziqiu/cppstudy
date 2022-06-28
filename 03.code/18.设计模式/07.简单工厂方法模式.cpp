#include <iostream>
using namespace std;

// 抽象水果
class AbstractFruit {
public:
    virtual void showName() = 0;
};

// apple
class apple : public AbstractFruit {
public: 
    virtual void showName()
    {
        cout << "apple" << endl;
    }
};

// peer
class peer : public AbstractFruit {
public: 
    virtual void showName()
    {
        cout << "peer" << endl;
    }
};

// banana
class banana : public AbstractFruit {
public: 
    virtual void showName()
    {
        cout << "banana" << endl;
    }
};

// 工厂
class AbstractFactory {
public:
    virtual AbstractFruit *CreateFruit() = 0;
};

class AppleFactory: public AbstractFactory {
public:
    virtual AbstractFruit *CreateFruit()
    {
        return new apple;
    }
};
class BananaFactory: public AbstractFactory {
public:
    virtual AbstractFruit *CreateFruit()
    {
        return new banana;
    }
};

class PeerFactory: public AbstractFactory {
public:
    virtual AbstractFruit *CreateFruit()
    {
        return new peer;
    }
};


void test01()
{
    // 创建的过程不需要关心，直接拿来用
    AbstractFactory *factory = NULL;
    AbstractFruit *fruit = NULL;

    // 创建一个appLe
    factory = new AppleFactory;
    fruit = factory->CreateFruit();
    fruit->showName();

    delete fruit;
    delete factory;

    // 
    factory = new BananaFactory();
    fruit = factory->CreateFruit();
    fruit->showName();
    delete fruit;
    delete factory;
}

int main()
{
   test01();

    return 0;
}