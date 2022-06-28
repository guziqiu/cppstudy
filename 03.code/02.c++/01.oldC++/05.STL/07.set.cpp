#include <iostream>
#include <set>
using namespace std;
// set/multiset 插入的时候会自动排序
// set 所有的值都是不相等的
// multiset 可以有重复的值
// 可以通过set迭代器可以改变元素的值吗？ 
// 不可以，删除结点再加上结点

//    初始化 自动排序 默认从小到大  拷贝构造  

// 仿函数
class mycompare {
public :  
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};
void test1() {
    
    set<int> s1;
    s1.insert(7);
    s1.insert(3);
    s1.insert(2);
    s1.insert(6);
    s1.insert(4);
    s1.insert(10);
    s1.insert(2);

    for (set<int>::iterator it = s1.begin(); it != s1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // 赋值操作
    set<int> s2 = s1;

    // 删除操作
    s1.erase(s1.begin());
    s1.erase(7);
    for (set<int>::iterator it = s1.begin(); it != s1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // cout << "====" << endl;
    // // 改变默认排序 从大到小
    // set<int, mycompare> s3;
    // s3.insert(7);
    // s3.insert(3);
    // s3.insert(2);
    // s3.insert(6);
    // s3.insert(4);
    // s3.insert(10);
    // s3.insert(2);
    // for (set<int>::iterator it = s1.begin(); it != s1.end(); ++it) {
    //     cout << *it << " ";
    // }
    // cout << endl;

}

// 查找
void test2() {
    // 实值
    set<int> s1;
    s1.insert(7);
    s1.insert(3);
    s1.insert(2);
    s1.insert(6);
    s1.insert(4);
    s1.insert(10);
    s1.insert(2);

    for (set<int>::iterator it = s1.begin(); it != s1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    set<int>::iterator ret = s1.find(4);
    if (ret == s1.end()) {
        cout << "没有找到！" << endl;
    } else {
        cout << "ret  : " << *ret << endl;
    }
    // 找到第一个>=key的元素
    ret = s1.lower_bound(11);
    if (ret == s1.end()) {
        cout << "没有找到" << endl;
    } else {
        cout << "ret : " << *ret << endl;
    }
    //  找到第一个大于key的值
    ret = s1.upper_bound(2);
    if (ret == s1.end()) {
        cout << "没有找到" << endl;
    } else {
        cout << "ret : " << *ret << endl;
    }

    // equal_range返回 lower_bound 和 upper_bound 返回两个迭代器 
    pair<set<int>::iterator, set<int>::iterator> myret = s1.equal_range(2);
    if (myret.first == s1.end()) {
        cout << "没有找到" << endl;
    } else {
        cout << "找到 lower_bound : " << (*myret.first) << endl;
    }
    if (myret.second == s1.end()) {
        cout << "没有找到" << endl;
    } else {
        cout << "找到 upper_bound : " << (*myret.second) << endl;
    }

}
class Person {
public :
    Person(int id, int age) : id(id), age(age) {}
    
public :
    int id;
    int age;
};
class cmp{
public :
    bool operator()(Person p1, Person p2) const {
        return p1.age < p2.age;
    }
};
void test3() {
    set<Person, cmp> s1;
    Person p1(10, 50), p2(30, 40), p3(50, 60);
    
    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);

    for (auto i : s1) {
        cout << i.id << " " << i.age << endl;;
    }
    cout << endl;

    // 查找
    Person p4(10, 60);
    set<Person, cmp>::iterator ret = s1.find(p4);
    if (ret == s1.end()) {
        cout << "没有找到" << endl;
    } else {
        cout << "找到 只会根据age查找，因为是根据age排序的:" << (*ret).id << " " << (*ret).age << endl;
    }

}

int main() {
    test3();

    return 0;
}
