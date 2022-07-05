#include <iostream>
using namespace std;

using namespace std;

// 一般情况下，用继承实现类的功能的拓展
// 装饰模式 可以动态的给一个类增加功能

// 抽象英雄
class AbstractHero {
public:
	virtual void ShowStatus() = 0;
public:
	int hp; // 血条
	int mp; // 蓝条
	int at; // 攻击
	int df; // 防御
};

// 具体英雄 
class HeroA: public AbstractHero {
public:
	HeroA() {
		hp = 0;
		mp = 0;
		at = 0;
		df = 0;
	}
	virtual void ShowStatus() {
		cout << "血条: " << hp << endl;
		cout << "蓝条: " << mp << endl;
		cout << "攻击: " << at << endl;
		cout << "防御: " << df << endl;
	}
};

// 英雄穿上某个装饰物 
// 装饰物基类
class AbstractEquipment : public AbstractHero {
public:
	AbstractEquipment(AbstractHero *hero) {
		this->pHero = hero;
	}

	virtual void ShowStatus() = 0;
public:
	AbstractHero *pHero;
};

// 狂徒
class KuangtuEquipment: public AbstractEquipment {
public:
	KuangtuEquipment(AbstractHero *hero) : AbstractEquipment(hero) {}
	// 增加额外功能
	void addKuangtu() {
		cout << "英雄穿上狂徒... 防御+30..." << endl;
		this->hp = this->pHero->hp;
		this->mp = this->pHero->mp;
		this->at = this->pHero->at;
		this->df = this->pHero->df + 30;

		delete this->pHero;
	}
	virtual void ShowStatus() {
		addKuangtu();
		cout << "血条: " << hp << endl;
		cout << "蓝条: " << mp << endl;
		cout << "攻击: " << at << endl;
		cout << "防御: " << df << endl;
	}
};

// 无尽之刃
class WujingKnife: public AbstractEquipment {
public:
	WujingKnife(AbstractHero *hero) : AbstractEquipment(hero) {}
	// 增加额外功能
	void addWujing() {
		cout << "英雄拿上无尽之刃... 攻击+80..." << endl;
		this->hp = this->pHero->hp;
		this->mp = this->pHero->mp;
		this->at = this->pHero->at + 80;
		this->df = this->pHero->df;

		delete this->pHero;
	}
	virtual void ShowStatus() {
		 addWujing();
		cout << "血条: " << hp << endl;
		cout << "蓝条: " << mp << endl;
		cout << "攻击: " << at << endl;
		cout << "防御: " << df << endl;
	}
};

void test() {
	AbstractHero *hero = new HeroA;
	hero->ShowStatus();

	cout << "-------" << endl;
	// 给裸奔的英雄穿上衣服
	hero = new KuangtuEquipment(hero);
	hero->ShowStatus();

	// 给英雄装备武器
	cout << "----" << endl;
	hero = new WujingKnife(hero);
	hero->ShowStatus();
}


int main() {
	test();

	return 0;
}
