#include <iostream>
using namespace std;

class DrinkTemplate {
public:
	// 煮水
	virtual void BoildWater() = 0;
	// 冲泡
	virtual void Brew() = 0;
	// 导入杯中
	virtual void PourInCup() = 0;
	// 加入辅料
	virtual void AddSomething() = 0;

	// 模板方法

	void Make() {
		BoildWater();
		Brew();
		PourInCup();
		AddSomething();
	}
};

// 冲咖啡
class Coffee : public DrinkTemplate {
public:
	// 煮水
	virtual void BoildWater() {
		cout << "boild water..." << endl;
	}
	// 冲泡
	virtual void Brew() {
		cout << "brew coffee..." << endl;
	}
	// 导入杯中
	virtual void PourInCup() {
		cout << "put coffee in cup..." << endl;
	}
	// 加入辅料
	virtual void AddSomething() {
		cout << "add somethin... " << endl;
	}
};

// 茶
class Tea : public DrinkTemplate {
public:
	// 煮水
	virtual void BoildWater() {
		cout << "boild water..." << endl;
	}
	// 冲泡
	virtual void Brew() {
		cout << "brew tea..." << endl;
	}
	// 倒入杯中
	virtual void PourInCup() {
		cout << "put tea in cup..." << endl;
	}
	// 加入辅料
	virtual void AddSomething() {
		cout << "add somethin... " << endl;
	}
};

void test01() {
	Tea *tea = new Tea();
	tea->Make();

	cout << "----" << endl;
	Coffee *coffee = new Coffee();
	coffee->Make();
}

int main() {

	test01();
	return 0;
}
