#include <iostream>

using namespace std;

class singleton_lazy {
private :
	singleton_lazy() { plazy = nullptr;}
public : 
	static singleton_lazy *getInstace()
	{
		if (nullptr == plazy)
		{
			plazy = new singleton_lazy();
		}
		return plazy;
	}
private :
	static singleton_lazy *plazy;
};



int main()
{


    return 0;
}