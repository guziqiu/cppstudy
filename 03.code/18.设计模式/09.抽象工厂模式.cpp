#include <iostream>
using namespace std;

// apple

class AbstractApple {
public:
    virtual void ShowName() = 0;
};
// chinese apple
class ChineseApple : public AbstractApple {
public:
    virtual void ShowName() {
        cout << "chenese apple" << endl;
    }
};

// usa apple
class USAApple : public AbstractApple {
public:
    virtual void ShowName() {
        cout << "usa apple" << endl;
    }
};

// Japan apple
class JapanApple : public AbstractApple {
public:
    virtual void ShowName() {
        cout << "jpenese apple" << endl;
    }
};

// banana
class AbstractBanana {
public:
    virtual void ShowName() = 0;
};
// chinese apple
class ChineseBanana : public AbstractBanana {
public:
    virtual void ShowName() {
        cout << "chenese Banana" << endl;
    }
};

// usa Banana
class USABanana : public AbstractBanana {
public:
    virtual void ShowName() {
        cout << "usa Banana" << endl;
    }
};

// jpenese Banana
class JapanBanana : public AbstractBanana {
public:
    virtual void ShowName() {
        cout << "jpenese Banana" << endl;
    }
};

// peer
class AbstractPeer {
public:
    virtual void ShowName() = 0;
};
// chinese Peer
class ChinesePeer : public AbstractPeer {
public:
    virtual void ShowName() {
        cout << "chenese Peer" << endl;
    }
};

// usa Peer
class USAPeer : public AbstractPeer {
public:
    virtual void ShowName() {
        cout << "usa Peer" << endl;
    }
};

// jpenese Banana
class JapanPeer : public AbstractPeer {
public:
    virtual void ShowName() {
        cout << "jpenese Peer" << endl;
    }
};
// 抽象工厂 针对产品族
class AbstractFactory {
public:
    virtual AbstractApple* CreateApple() = 0;
    virtual AbstractBanana* CreateBanana() = 0;
    virtual AbstractPeer* CreatePeer() = 0;
};

// 中国工厂
class ChineseFactory : public AbstractFactory {
public:
    virtual AbstractApple* CreateApple() {
        return new ChineseApple;
    }
    virtual AbstractBanana* CreateBanana() {
        return new ChineseBanana;
    }
    virtual AbstractPeer* CreatePeer() {
        return new ChinesePeer;
    }
};

// USA工厂
class USAFactory : public AbstractFactory {
public:
    virtual AbstractApple* CreateApple() {
        return new USAApple;
    }
    virtual AbstractBanana* CreateBanana() {
        return new USABanana;
    }
    virtual AbstractPeer* CreatePeer() {
        return new USAPeer;
    }
};

// japan工厂
class JapanFactory : public AbstractFactory {
public:
    virtual AbstractApple* CreateApple() {
        return new JapanApple;
    }
    virtual AbstractBanana* CreateBanana() {
        return new JapanBanana;
    }
    virtual AbstractPeer* CreatePeer() {
        return new JapanPeer;
    }
};

void test01()
{
    AbstractFactory* factory = nullptr;
    AbstractApple* apple = nullptr;
    AbstractBanana* banana = nullptr;
    AbstractPeer* peer = nullptr;

    // 中国工厂
    factory = new ChineseFactory;
    apple = factory->CreateApple();
    banana = factory->CreateBanana();
    peer = factory->CreatePeer();

    apple->ShowName();
    banana->ShowName();
    peer->ShowName();

    delete apple;
    delete banana;
    delete peer;
}

int main()
{

    test01();
    return 0;
}