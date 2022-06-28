#include <iostream>
#include <map>
using namespace std;

// map初始化
void test1() {
    map<int,int> mymap; // map容器模板参数，第一个参数key的类型，第二个参数value的类型
     
    // 插入数据  pair.first   key值， pair.second value值
    // 1
    pair<map<int, int>::iterator, bool> ret = mymap.insert(pair<int, int>(10, 10));
    if (ret.second) {
        cout << "第一次插入成功 " << endl;
    } else {
        cout << "插入失败" << endl;
    }



    // 第二种
    ret = mymap.insert(make_pair(10, 20));
    if (ret.second) {
        cout << "第二次插入成功 " << endl;
    } else {
        cout << "第二次插入失败" << endl;
    }

    // 3
    ret = mymap.insert(map<int, int>::value_type(30, 30));
    if (ret.second) {
        cout << "第三次插入成功 " << endl;
    } else {
        cout << "插入失败" << endl;
    }
    // 4
    mymap[40] = 40;
    mymap[50] = 5;
    mymap[10] = 100;
    // 如果发现key不存在，会创建pair插入到map的容器中
    // 如果发现key存在，那么会修改key对应的value
    cout << mymap[90] << endl;
    // 如果通过方括号的方式访问map中一个不存在的key,
    // 那么map会将这个访问的key插入到map中，并进行默认初始化

    // 打印
    for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
        cout << (*it).first << " " << (*it).second << " ++  ";
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
    for (auto i : mymap) {
        cout << i.first << " " << i.second << endl;
    }
    
}

class mykey {
public :
    mykey(int ind, int id) {
        this->mind = ind;
        this->nid = id;
    }
    int mind;
    int nid;
};
struct cmp {
    bool operator()(mykey k1, mykey k2) const {
        return k1.mind < k2.mind;
    }
};
void test2() {
    map<mykey, int, cmp> mymap;
    mymap.insert(make_pair(mykey(1,2), 10));
    mymap.insert(make_pair(mykey(4,5), 20));
    for (auto i : mymap) {
        cout << i.first.mind << " " << i.first.nid << " = " << i.second << endl;
    }
}


int main() {
    test2();

    return 0;
}
