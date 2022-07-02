#include <iostream>
using namespace std;

// 提供一种代理来控制对其他对象的访问
class AbstractCommonInterface {
public:
	virtual void run() = 0;
};

// 我已经写好的系统
class MySystem : public AbstractCommonInterface {
public:
	virtual void run() {
		cout << "系统启动。。。" << endl;
	}
};

// 必须要有权限验证，不是所有人都能来启动我的启动，提供用户名和密码

class MySystemProxy : public AbstractCommonInterface {
public:
	MySystemProxy(string username, string passwd) {
		this->username = username;
		this->passwd = passwd;
		pSystem = new MySystem;
		i++;
	}

	bool checkUsernameAndPasswd() {
		if ("admin" == username && "admin" == passwd) {
			return true;
		}
		return false;
	}
	virtual void run() {
		if (checkUsernameAndPasswd()) {
			cout << "username and passwd is right ..." << endl;
			pSystem->run();
		}
		else {
			cout << "username or passwd is error" << endl;
		}
	}

	~MySystemProxy() {
		if (nullptr != pSystem) {
			pSystem = new MySystem;
		}
	}
public:
	MySystem *pSystem;
	string username;
	string passwd;
	int i;
};

void test01() {
	MySystemProxy *proxy = new MySystemProxy("admin", "admin");
	proxy->run();

	// proxy = new MySystemProxy("admin", "admin");
	// proxy->run();
	return ;
}

int main()
{
	test01();

	return 0;
}