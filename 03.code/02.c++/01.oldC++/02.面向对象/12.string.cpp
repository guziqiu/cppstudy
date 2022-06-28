#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "I am  guziqiu. I don't like c++.";
    string name = "我是古子秋!";
    
    
    cout << "1.find(am):" << str.find("am") << endl;
    str.insert(0,name);
    cout << "2.insert(name):" << str << endl;
    cout << "3.substr(9, 10):" << str.substr(9, 10) << endl;
    cout << endl;

    str.append(name);
    cout << str << endl;

    int i = 7;
    
    str.replace(str.find(" "), 1, "%20");
    cout << "4.删除从str.find()开始的1个字符，然后在str.find()处插入串%20" <<  endl;
    cout << str << endl;
    cout << "5.swap(name)，互换name和str的内容：";
    str.swap(name);
    cout << "str = " << str << "name = " << name << endl;
    cout << "6.assign(asd)修改str内容为asd:";
    str.assign("asd");
    cout << str << endl;
     
    

    return 0;
}