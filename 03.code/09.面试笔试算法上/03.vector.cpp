#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    for (int i = 105; i <= 110; i++) {
        v.push_back(i);
        cout << "v.size() = "<< v.size() << endl;
    }
    for (int i = 0; i < v.size(); i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }
    cout << "==========" << endl;

    vector<vector<int> > v1;
    v1.push_back(vector<int>());//插入一个空的vector()
    for (int i = 66; i <= 70; i++) {
        v1[0].push_back(i);//在第一行插入
    }
    v1.push_back(vector<int>(5, 55));// 5个值为55的元素
    
    vector<int> v2;
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    
    v1.push_back(v2);
    v1.push_back(vector<int>(10, 1));

    for (int i = 0; i < (int)v.size(); i++) {//打印数组
        //整体作为二维数组输出
        for (int j = 0; j < (int)v1[i].size(); j++) {
            printf("v1[%d][%d] = %d ",i, j, v1[i][j]);
            //cout << v1[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}

