#include <iostream>
using namespace std;

// 
class AbsCar
{
public:
	virtual void run() = 0;
};

// dahzong
class dazhong : public AbsCar
{
public:
	virtual void run()
	{
		cout << "da zhong ..." << endl;
	}
};

class dahuangfeng : public AbsCar
{
public:
	virtual void run()
	{
		cout << "da zhong ..." << endl;
	}
};

class person : public dahuangfeng, public dazhong
{
	// s
};

class person2
{
public:
	void SetCar(AbsCar *car)
	{
		this->car = car;
	}
	void run()
	{
		car->run();
	}
	~person2()
	{
		delete car;
	}
public:
	AbsCar *car;
};

int main() {
	person2 p;
	p.SetCar(new dahuangfeng);
	p.run();

	return 0;
}
