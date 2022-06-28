#include <iostream>
using namespace std;

void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (num[j] < num[j - 1]) swap(num[j], num[j - 1]);
        }
    }
    return ;
}

void double_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (num[i] > num[j]) swap(num[i], num[j]);
        }
    }
}


int main() {
    
    return 0;
}

