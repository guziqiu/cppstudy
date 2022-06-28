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

struct node {
    string name; // 姓名
    int grade; // 期末平均成绩
    int cgrade; // 班级评议成绩
    string classgrade; // 是否是学生干部
    string xi; // 是否是西部省份学生
    int num; // 发表的论文数
};

int main() {
        

    int n;
    cin >> n;
    string name;
    int maxm = 0;
    int sum = 0;
    

    for (int i = 0; i < n; i++) {
        int temp = 0;
        node stu;
        cin >> stu.name >> stu.grade >> stu.cgrade >> stu.classgrade >> stu.xi >> stu.num;
        if (stu.grade > 80 && stu.num >= 1) temp += 8000;
        if (stu.grade > 85 && stu.cgrade > 80) temp += 4000;
        if (stu.grade > 90) temp += 2000;
        if (stu.xi == "Y" && stu.grade > 85) temp += 1000;
        if (stu.cgrade > 80 && stu.classgrade == "Y") temp += 850;
        if (sum < temp) sum = temp, name = stu.name;
        maxm += temp;
    }

    cout << name << endl;
    cout << sum << endl;
    cout << maxm << endl;






    return 0;
}

