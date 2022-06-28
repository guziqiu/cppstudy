#include <iostream>
#include <stack>
using namespace std;

class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
		a.push(value);
    };
    
    int deleteHead() {
		if (b.empty()) {
			while(!a.empty()) {
				b.push(a.top());
				a.pop();
			}
		}
		if (b.empty()) {
			return -1;
		}
		int ret = b.top();
		b.pop();
		return ret;
    };

private:
	stack<int> a;
	stack<int> b;
};
int main() {

	CQueue* obj = new CQueue();
	obj->appendTail(5);
	obj->appendTail(2);
	cout << obj->deleteHead() << ",";
	cout << obj->deleteHead() << endl;

	return 0;
}
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */