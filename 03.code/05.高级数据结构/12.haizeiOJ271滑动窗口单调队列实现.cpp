#include <iostream>
using namespace std;

#define MAX_N 300000
int queue[MAX_N + 5];//维护数组的单调队列，存储数组下标
int head = 0, tail = 0;//头指针，尾指针
int val[MAX_N + 5];//数组

int main() {
    int n, k;
    cin >> n >> k;//给出一个长度为 𝑁 的数组,一个长为 𝐾 的滑动窗口
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= n; i++) {//滑动窗口最小值，用单调递增队列
        while ((tail - head) && val[queue[tail - 1]] > val[i]) --tail;
        //队列中有元素，并且当前队尾元素的值>要入队的元素，大于要入队的元素全部出队
        queue[tail++] = i;//存储下标
        if (queue[head] <= i - k) head++;
        if (i >= k) {
            i > k && cout << " ";
            cout << val[queue[head]];
        }
    }
    cout << endl;
    
    head = tail = 0;//队列清空
    for (int i = 1; i <= n; i++) {//滑动窗口最大值，用单调递减队列
        while ((tail - head) && val[queue[tail - 1]] < val[i]) --tail;
        //队列中有元素，并且当前队尾元素的值 < 要入队的元素，小于要入队的元素全部出队
        queue[tail++] = i;//存储下标
        if (queue[head] <= i - k) head++;
        if (i >= k) {
            i > k && cout << " ";
            cout << val[queue[head]];
        }
    }
    cout << endl;
    return 0;
}

