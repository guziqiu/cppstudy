#include <iostream>
#include <deque>
using namespace std;

//dequeue 双端队列， 
// 可以从尾部插入，删除push_bck,pop_back
// 可以从头部插入，删除 pop_front, push_front
// 和vector一样，支持随机存储，双向开口的连续性空间，在头部插入常数
// 动态 连续空间 随时可以增加一端新的空间，没有容器的概念
// 插入删除元素效率高
// 指定位置插入会导致元素移动，降低效率
// 支持随机存取，效率高

// 初始化
void test1() {
    deque<int> d;
    deque<int> d2(10, 5);
    deque<int> d3(d2.begin(), d2.end());
    deque<int> d4(d3);

    for (auto it : d4) {
        cout << it << " ";
    }
    cout << endl;

}


// 赋值 初始化
void test2() {
    deque<int> d;
    deque<int> d2;
    deque<int> d3;
    d.assign(10, 2);

    for (int it : d) {
        cout << it << " ";
    }
    cout << endl;

    d2.assign(d.begin(), d.end());
    for (int it : d2) {
        cout << it << " ";
    }
    cout << endl;

    // assign(beg, end)将[beg, end) 区间中的数据拷贝赋值给本身
    // assign(n, elem); 将n个elem拷贝赋值给本身

    d3 = d2;// 等号赋值
    for (int it : d3) {
        cout << it << " ";
    }
    cout << endl;

    // 自动清 0,在缓冲区排序
     
    d.swap(d2); // 交换两个空间的元素
    

    if (d.empty()) { // 判断容器是否为空
        cout << "空 ！"  << endl; 
    } else {
        cout << "非空！"  << endl;
    }
    cout << endl;
    d.resize(5); // 10个元素，后5个元素扔掉
    for (auto it : d) {
        cout << it << " ";
    }
    cout << endl;
}

void test3() {
    // deque插入和删除
    deque<int> d1;
    d1.push_back(100);
    d1.push_front(200);
    d1.push_back(200);
    d1.push_back(300);
    d1.push_front(300);
    for (deque<int>::iterator it = d1.begin(); it != d1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    int val = d1.front();
    d1.pop_front();
    cout << val << endl;
    cout << d1.back() << endl;
    d1.pop_back(); // 删除最后一个元素
    for (deque<int>::iterator it = d1.begin(); it != d1.end(); ++it) {
        cout << *it << " ";
    }
    return ;
}

int main() {
    test3();

    return 0;
}
