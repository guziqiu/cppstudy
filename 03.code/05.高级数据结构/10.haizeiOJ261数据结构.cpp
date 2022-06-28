#include <iostream>
#include <vector>
#include <stack>
#include <cinttypes>
using namespace std;

class NewStruct {
public:
    NewStruct() {
        sum[0] = 0;//sum[0] = 0;
        ans[0] = INT64_MIN;
    }
    void insert(int x) {//插入元素
        s1.push(x);//在s1中插入
        long long val = s1.top() + sum[s1.size() - 1];
        sum[s1.size()] = val;//前i项和
        ans[s1.size()] = max(ans[s1.size() - 1], val);//前i项和的最大值，在前i项和sum和前i-1项和中的最大值做比较
        return ;
    }
    void del() {
        if (s1.empty()) return ;
        s1.pop();
        return ;
    }
    void move_left() {
        if (s1.empty()) return ;
        s2.push(s1.top());
        del();
        //s1.pop();
        return ;
    }
    void move_right() {
        if (s2.empty()) return ;
        insert(s2.top());
        //s1.push(s2.top());
        s2.pop();
        //sum.pop_back(s2.top());
        //ans.push_back(s1.top() + sum[sum.size() - 1]);
    }
    long long query(int k) {
        return ans[k];
    }
private:
    stack<long long> s1, s2;
    long long sum[1005];
    long long ans[1005];
};

int main() {
    long long n;
    cin >> n;//输入第一行为操作数 𝑁。
    string op;
    int val;
    NewStruct s;
    for (int i = 0; i < n; i++) {
        cin >> op;
        switch(op[0]) {
        case 'I': cin >> val; s.insert(val); break;//在当前位置插入 𝑥 元素；
        case 'D': s.del(); break;// 删除当前位置的元素；
        case 'L': s.move_left(); break;//将当前位置左移一位，除非它已经是第一个元素；
        case 'R': s.move_right(); break;//将当前位置右移一位，除非它已经是最后一个元素
        case 'Q': cin >> val; cout << s.query(val) << endl; break;//𝑘  在当前位置之前，找到一个最大的 𝑆𝑖(1≤𝑖≤𝑘,𝑆𝑖=𝑎1+𝑎2+...+𝑎𝑖)
        default : cout << "error" << endl; break;
        }
    }


    return 0;
}

