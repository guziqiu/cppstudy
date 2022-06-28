#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct student {
    string name;
    string sex;
    int year;
    int mouth;
    bool operator<(const student &stu) const {
        if (this->year < stu.year){
            //cout << this->name << " this->year = " << this->year << ", stu.year = " << stu.year << endl;
            return false;
        } else if (this->year > stu.year) {
            return true;
        }
        else {
            if (this->mouth > stu.mouth) return true;
            return false;
        }
    }
  
};

ostream &operator<<(ostream &out, const student &stu){
    out << stu.name << " " << stu.sex << " " << stu.year << " " << stu.mouth;
    return out;
}

int main() {
    int n;
    cin >> n;


    struct student stu;
    vector<struct student> sv;
    

    for (int i = 0; i < n; i++) {
        cin >> stu.name >> stu.sex >> stu.year >> stu.mouth;
        sv.push_back(stu);
    }

    //cout << endl;

    sort(sv.begin(), sv.end());

    for (int i = 0; i < sv.size(); i++) {
        cout << sv[i] << endl;
    }

    



    return 0;
}

