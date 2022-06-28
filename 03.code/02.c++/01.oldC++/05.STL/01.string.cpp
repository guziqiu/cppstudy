#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abc";
    cout << s << endl;
    s += "abc";
    cout << s << endl;
    string s1 = "123";
    s += s1;
    cout << s << endl;
    string s3 = "222";
    s.append(s3);
    cout << s << endl;
    string s4 = s1 + s3;
    cout << s4 << endl;
    cout << s << endl;
    cout << s.find("1") << endl;

    cout << s << endl;
    s.replace(0, 2, "111");
    cout << s << endl;

    string s11 = "abcd";
    string s12 = "abcd";
    cout << s11.compare(s12) << endl;
    //cout << s12 - s11 << endl;
    if (s11.compare(s12) == 0) {
        cout << "==" << endl;
    } else if(s11.compare(s12) < 0){
        cout << "<" << endl;
    } else {
        cout << ">" << endl;
    }
    cout << "+====" << endl;
    cout << s << endl;
    cout << s.substr(1, 3) << endl;
    cout << s << endl;

    cout << "+====" << endl;
    cout << s << endl;
    cout << s.insert(3, "kkk") << endl;
    cout << s << endl;
    s.erase(0, 2);
    cout << s << endl;


    return 0;
}
