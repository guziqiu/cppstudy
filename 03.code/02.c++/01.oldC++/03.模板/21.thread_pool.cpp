#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <unordered_map>
#include <mutex>
#include <condition_variable> // 条件型号量

namespace guziqiu {

class Task { // 任务队列
public :
    template<typename FUNCTION, typename ...ARGS>
    Task(FUNCTION &&func, ARGS ...args);
    void run();

private :
    std::function<void()> func;
};


class ThreadPool {
public :
    ThreadPool(int n = 5);
    template<typename FUNCTION, typename ...ARGS>
    void addOneTask(FUNCTION &&, ARGS...);
    void stop(); // 等待线程池执行结束
private :
    std::vector<std::thread *> threads;
    std::queue<Task *> tasks;
    std::unordered_map<std::thread::id, bool> running;
    std::mutex m_mutex; // 互斥锁 
    std::condition_variable m_condition; // 条件信号量

    void workerThread(); // 入口函数
    Task *getOneTask();
    void stopThread(); // 毒药任务
};


template<typename FUNCTION, typename ...ARGS>
Task::Task(FUNCTION &&func, ARGS ...args) {
    this->func = std::bind(func, std::forward<ARGS>(args)...);
}
void Task::run() {
    std::cout << "Task run : " << std::endl;
    func();
    return ;
}


ThreadPool::ThreadPool(int n) {
    for (int i = 0; i < n; i++) {
        threads.push_back(new std::thread(&ThreadPool::workerThread, this));
    }
}
template<typename FUNCTION, typename ...ARGS>
void ThreadPool::addOneTask(FUNCTION &&func, ARGS... args) {
    std::unique_lock<std::mutex> lock(m_mutex); // 抢占互斥锁
    tasks.push(new Task(func, std::forward<ARGS>(args)...)); // 添加任务
    m_condition.notify_one(); // 通知其他线程已经有任务了
}
void ThreadPool::workerThread() { // 入口函数
    std::thread::id id = std::this_thread::get_id();
    // std::cout << id << std::endl;
    running[id] = true;
    while (running[id]) {
       Task *t = this->getOneTask(); // 取任务
        t->run();// 执行任务
       delete t; // 销毁任务
    }
    return ;
}
Task *ThreadPool::getOneTask() {
    // 取任务
    std::unique_lock<std::mutex> lock(m_mutex);// 抢占互斥锁
    while (tasks.empty()) { // 当任务队列为空
        m_condition.wait(lock); // 等待任务
    }
    Task *t = tasks.front();
    tasks.pop();

    return t;
}

void ThreadPool::stop() {
    for (int i = 0; i  < threads.size(); i++) {
        this->addOneTask(&ThreadPool::stopThread, this); // 添加毒药任务
    }

    for (auto t : threads) {
        t->join(); // 等待线程结束
    }
    return ;
}

void ThreadPool::stopThread() {
    std::thread::id id = std::this_thread::get_id();
    running[id] = false;
    return ;
}



} // ed of guziqiu


void  func(int a, int b, int c) {
    
    std::cout << "func id : " << a << ", "<< a + b + c << std::endl;
    return ;
}






int main() {

    guziqiu::Task t1(func, 1, 2, 3);
    guziqiu::ThreadPool tp;
    //std::cout << "hello, world" << std::endl;
    //t1.run();

    // 在线程池中添加100个任务
    for (int i = 0; i < 100; i++) {
        tp.addOneTask(func, i, 2 * i, 3 * i);
    }


    tp.stop(); // 等待线程池中的任务执行结束







    
    return 0;
}

