#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 最少知识原则  又叫最少知识原则

class AbstrBuild
{
public :
	virtual void sale() = 0;
public:
	string m_qulity;
};


class buildA : public AbstrBuild
{
public :
	buildA()
	{
		m_qulity = "high";
	}

	virtual void sale()
	{
		cout << m_qulity << " is saled" << endl;
	}

	// string m_qulity;
};

class buildB : public AbstrBuild
{
public :
	buildB()
	{
		m_qulity = "low";
		// cout << m_qulity << endl;
	}

	virtual void sale()
	{
		cout << m_qulity << "is saled" << endl;
	}

	// string m_qulity;
};

class mediator
{
public:
	mediator()
	{
		AbstrBuild *b = new buildA;
		v_b.push_back(b);

		b = new buildB;
		v_b.push_back(b);
	}
	~mediator()
	{
		for (vector<AbstrBuild *>::iterator it = v_b.begin();
			it != v_b.end(); ++it)
			{
				if (*it != NULL)
				{
					delete *it;
				}
			}
	}

	// 对外提供接口
	AbstrBuild *findMyBuild(string q)
	{
		for (vector<AbstrBuild *>::iterator it = v_b.begin();
			it != v_b.end(); ++it)
		{
			if ((*it)->m_qulity == q)
			{
				return *it;
			}
		}
		return NULL;
	}

	vector<AbstrBuild *> v_b;
};


int main() {
	// 1
	AbstrBuild *a = new buildA;
	cout << a->m_qulity << endl;
	if (a->m_qulity == "high")
	{
		a->sale();
	}

	AbstrBuild *b = new buildB();
	if (b->m_qulity == "low")
	{
		b->sale();
	}

	// 
	mediator *me = new mediator;
	AbstrBuild *bu = me->findMyBuild("high");
	if (NULL != bu)
	{
		bu->sale();
	}

	return 0;
}
