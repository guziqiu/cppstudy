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
class FruitFactory {
public:
    static AbstractFruit* CreateFruit(const string &flag)
    {
        if ("apple" == flag)
        {
            return new apple;
        }
        else if ("banana" == flag)
        {
            return new banana;
        }
        else if ("peer" == flag)
        {
            return new peer;
        }
        else
        {
            return NULL;
        }
    }
};

void test01()
{
    // 创建的过程不需要关心，直接拿来用
     FruitFactory *factory = new FruitFactory;
     AbstractFruit *fruit = factory->CreateFruit("apple");
     fruit->showName();
     AbstractFruit *banana = factory->CreateFruit("banana");
     banana->showName();

     delete fruit;
     fruit = factory->CreateFruit("peer");
     fruit->showName();
     delete factory;
}

int main()
{
   test01();

    return 0;
}