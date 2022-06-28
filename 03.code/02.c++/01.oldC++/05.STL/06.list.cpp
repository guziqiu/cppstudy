#include <iostream>
#include <list>
using namespace std;

// 链表 是由一系列的结点组成，结点包含两个域，一个数据域，一个指针域
// 链表内存是非连续的，
// 添加删除效率高， 时间复杂度是常数，不需要移动元素，比数组添加删除效率高
// 链表只有在需要的时候，才分配内存
// 需要额外的空间保存结点关系， 有前驱和后继

// 初始化 

void test() {
    list<int> l;
    list<int> l2(10, 10); // 有参构造
    list<int> l3(l2); // 拷贝构造
    list<int> l4(l3.begin(), l3.end());

    for (auto i : l4) {
        cout << i << " ";
    }
    cout << endl;
    
}
void test1() {
    list<int> l1;
    l1.push_back(100);
    l1.push_front(200);
    for (auto i : l1) {
        cout << i << " ";
    }
    cout << endl;


    l1.insert(l1.begin(), 300);
    l1.insert(l1.end(), 300);
    for (auto i : l1) {
        cout << i << " ";
    }
    cout << endl;

    list<int>::iterator it = l1.begin();
    l1.insert(++(++it), 500);
    for (auto i : l1) {
        cout << i << " ";
    }
    cout << endl;
    l1.remove(300); // 删除匹配的所有值
    for (auto i : l1) {
        cout << i << " ";
    }
    cout << endl;
    

    l1.pop_back();
    l1.pop_front();

    l1.erase(l1.begin(), l1.end());
    return ;
    
}

// 大小操作 赋值操作
void test2() {
    list<int> l1;
    l1.assign(10, 10);
    list<int> l2;
    l2 = l1;
    for (auto i : l2) {
        cout << i << endl;
    }
    cout << endl;
    l1.swap(l2);
}
// 反转
void test4() {
    list<int> l1;
    for (int i = 0; i < 10; i++) {
        l1.push_back(i);
    }
    l1.reverse();
    for (auto i : l1) {
        cout << i << " ";
    }
    cout << endl;
}
bool cmp(int x, int y) {
    return x > y;
}
// 排序
void test5() {
    list<int> l1;
    l1.push_back(2);
    l1.push_back(1);
    l1.push_back(5);
    l1.push_back(9);

    for (auto i : l1) {
        cout << i << " ";
    }
    cout << endl;
    l1.sort();  // 默认从小到大
    for (auto i : l1) {
        cout << i << " ";
    }
    cout << endl;

    l1.sort(cmp); // 从大到小
    for (auto i : l1) {
        cout << i << " ";
    }
    cout << endl;
    

}

//  sort仅支持可随机访问的容器
// list不支持随机访问


int main() {
    test5();

    return 0;
}
