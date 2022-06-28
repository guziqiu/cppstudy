#include <iostream>
#include <vector>
using namespace std;

/// 初始化
//vector<T> v; /// 采用模板类实现。默认构造
// vector(v.begin(), v.end()); // vector<int> v1(arr, arr + sizeof(arr/ sizeof(int)));
// vector(n, elem)   
// vector(const vector &vec);
// int arr[] = {2, 3, 4, 1, 9};
void test01() {
    vector<int> v1;
    int arr[] = {10, 20, 30, 40};
    vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));
    vector<int> v3(v2.begin(), v2.end());
    vector<int> v4(v2);
    for (vector<int>::iterator it = v4.begin(); it != v4.end(); ++it) {
        cout << (*it) << endl;
    }
    return ;
}
// 赋值
void test02() {
    int arr[] = {10, 20, 30, 40};
    vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
    
    vector<int> v2;
    v2.assign(v1.begin(), v1.end());

    for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
        cout << (*it) << endl;
    }
    return ;
}

// 大小操作
void test3() {
    int arr[] = { 100, 200, 300, 400};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int)); // 默认构造
    cout << "size : " << v.size() << endl;
    if (v.empty()) {
        cout << "空！" << endl;
    } else {
        cout << "不空" << endl;
    }
    for (auto it : v) cout << it << " ";
    cout << endl;
    v.resize(2); // 扔掉后面的
    for (auto it : v) cout << it << " ";
    cout << endl;
    v.resize(6, 1); // 增加后面的， 默认1
    for (auto it : v) cout << it << " ";
    cout << endl;

    cout << "size :" << v.size() << endl;
    cout << "容量capacity :" << v.capacity() << endl;

    return ;
}

// 存取数据
void test4() {
    int arr[] = { 100, 200, 300, 400};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int)); // 默认构造
    cout << "size : " << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    // cout << v[v.size()] << endl; // 不会抛出异常
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    // cout << v.at(v.size()) << endl;// 会抛出异常

    cout << "front : " << v.front() << endl;
    cout << "back : " << v.back() << endl;

    return ;
}

// 插入和删除
void test5() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    // 头插法
    v.insert(v.begin(), -1);
    v.insert(v.end(), 30);
    v.insert(v.begin() + 2, 222); // vector支持随机访问
    // 支持数组下表，一般都支持随机访问
    // 迭代器可以直接 + 2 + 3 -2  -5操作
    for (auto it : v) cout << it << " ";
    cout << endl;

    // 删除
    v.erase(v.begin());
    for (auto it : v) cout << it << " ";
    cout << endl;
    v.erase(v.begin() + 1, v.end());
    for (auto it : v) cout << it << " ";
    cout << endl;
    v.clear();
    cout << "size : " << v.size() << endl;

}

// 巧用swap缩减空间
void test6() {
    // vector添加元素 塔湖自动增长， 你删除的元素的时候，他不会自动减少
    vector<int> v;
    for (long long i = 0; i < 10000000; i++) {
        v.push_back(i);
    }
    cout << "size : " << v.size() << endl;
    cout << "capacity :" << v.capacity() << endl;


    v.resize(10);
    cout << "=======" << endl;
    cout << "size : " << v.size() << endl;
    cout << "capacity :" << v.capacity() << endl;

    vector<int>(v).swap(v);
    cout << "=======" << endl;
    cout << "size : " << v.size() << endl;
    cout << "capacity :" << v.capacity() << endl;
}

//  
void test7() {
    // resverse 预留空间 resize 区别
    vector<int> v;
    int num = 0;
    int *address = NULL;
    v.reserve(100000);
    for (int i = 0; i < 10000000; i++) {
        v.push_back(i);
        if (address != &(v[0])) {
            address = &(v[0]);
            num++;
        }
    }
    cout << "num : " << num << endl;
    // 如果知道需要的空间，可以用reverse预留空间，减少拷贝新空间的时间

}


int main() {

    test7();

    return 0;
}
