#include <iostream>
#include <functional>
#include <thread>
#include <vector>
#include <unordered_map>
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;

class Task{
private:
	function<void()> func;
public:
	template <typename FUNC_T, typename ...ARGS>
	Task(FUNC_T f, ARGS ...args) {
		func = bind(f, forward<ARGS>(args)...);
	}

	void run() {
		func();
	}
};

class ThreadPool {
public:
	ThreadPool(int n = 1): trr(n), starting(false) {
		this->start();
	}

	void worker() {
		thread::id id = this_thread::get_id();
		running[id] = true;
		while (running[id]) {
			// 获取任务
			Task *t = get_task();
			// 执行操作
			t->run();
			delete t;
		}
	}

	void start() {
		if (starting) {
			return ;
		}

		for (int i = 0; i < trr.size(); ++i) {
			trr[i] = new thread(&ThreadPool::worker, this);
		}

		starting = true;
	}

	void stop() {
		if (!starting)
		{
			return ;
		}
		for (int i = 0; i < trr.size(); ++i) {
			add_task(&ThreadPool::stop_running, this);
		}

		for (int i = 0; i < trr.size(); ++i) {
			trr[i]->join();
		}
		for(int i = 0; i < trr.size(); ++i) {
			delete trr[i];
			trr[i] = nullptr;
		}
		starting = false;
	}

	template <typename FUNC_T, typename ...ARGS>
	void add_task(FUNC_T f, ARGS ...args) {
		// 上锁
		unique_lock<mutex> lock(mtx);
		task_q.push(new Task(f, forward<ARGS>(args)...));
		// 解锁,同时通知队列中有任务的条件已经达成
		condi.notify_one();
		return ;
	}

	virtual ~ThreadPool() {
		this->stop();
		while (!task_q.empty()) {
			delete task_q.front();
			task_q.pop();
		}
	}
private:
	void stop_running() {
		auto id = this_thread::get_id();
		running[id] = false;
		return ;
	}

	Task *get_task() {
		unique_lock<mutex> lock(mtx);

		while (task_q.empty()) {
			condi.wait(lock);
		}
		Task *t = task_q.front();
		task_q.pop();
		return t;
	}

private:
	vector<thread *> trr;
	unordered_map<thread::id, bool> running;
	queue<Task *> task_q;
	mutex mtx;
	condition_variable condi;

	bool starting;
};

bool is_prime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

int cnt = 0;
int count_prime(int l, int r) {

	int ret = 0;
	for (int i = l; i <=r; ++i) {
		ret += is_prime(i);
	}

	return ret;
}

void worker(int l, int r, int &ret) {
	cout << this_thread::get_id() << ":begin" << endl;
	ret = count_prime(l, r);
	cout << this_thread::get_id() << ":end" << endl;
}

// 计算 5000w内有多少个素数
int main() {
	const int batch = 5000000;


	int ret[10];
	ThreadPool tp(5);
	for (int i = 0, j = 1; i < 10; ++i, j += batch) {
		tp.add_task(worker, j, j + batch - 1, ref(ret[i]));
	}

	tp.stop();

	int ans = 0;
	for (auto x : ret) {
		ans += x;
	}

	cout << ans << endl;


	return 0;
}