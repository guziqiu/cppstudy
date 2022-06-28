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
    int n; //第1行一个正整数𝑛,表示学员人数𝑛≤1000。
    cin >> n;

    //第2 ~​ 𝑛+1行，每行一个字符和一个字符串，中间用一个空格隔开。
    //第一个字符表示这个学生成绩类型，有𝐶、𝑁两种分别代表等级表示和分数表示，第二个字符串表示成绩信息。
    string a, b;
    int sum1 = 0;
    int sum2 = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (b == "best" || b == "good" || b == "poor"){
            sum1++;
            continue;
        } 
        sum2 += atoi(b.c_str());
        t++;
    }
    cout << sum1 << " " << (sum2 / t) << endl;


    return 0;
}
