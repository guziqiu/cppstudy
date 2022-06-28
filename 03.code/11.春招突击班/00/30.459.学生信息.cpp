#include <iostream>
#include <cmath>
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

int main() {

    //输入一个学生的信息，包括姓名、性别、年龄、体重，再输出这些信息。
    string name;
    string sex;
    int age;
    double height;
    cin >> name >> sex >> age >> height;

    cout << name << " " << sex << " " << age << " ";
    printf("%.1f\n", height);

    


    return 0;
}
