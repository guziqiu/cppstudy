#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 已经写好的类
struct MyPrint {
	void operator() (int v1, int v2) {
		cout << v1 + v2 << endl;
	}
};

// 定义的接口 需要适配的类
class Target {
public:
	virtual void operator()(int v) = 0;
};

// 适配器
class Adaptor: public Target {
public:
	Adaptor(int param) {
		this->param = param;
	}
	virtual void operator()(int v) {
		print(v, param);
	}
public:
	MyPrint print;
	int param;
};

Adaptor MyBind2nd(int v) {
	return Adaptor(v);
}

int main() {
	vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), MyBind2nd(10));

	return 0;
}
