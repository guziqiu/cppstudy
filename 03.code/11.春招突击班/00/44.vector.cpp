#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;


#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)


typedef struct Vector {
    int *data;
    int size, length;
} vec;

vec *init(int n) {
    vec *v = (vec *)malloc(sizeof(vec)); // malloc申请的是内存上的堆区，不在栈区
    v->data = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;
    return v;
}

int expand(vec *v) {
    int extr_size = v->size;
    int *p;
    while (extr_size) {
        p = (int *)realloc(v->data, sizeof(int) * (v->size + extr_size));
        if (p) break;
        extr_size >>= 1;
    }
    if (p == NULL) return 0;
    v->data = p;
    v->size += extr_size;
    return 1;
}

int insert(vec *v, int ind, int val) {
    if (v == NULL) return 0;
    if (ind < 0 || ind > v->length) return 0;
    if (v->length == v->size) {
        if (!expand(v)) return 0;
        cout << GREEN("success to expand ! the size = ") << v->size << endl;
    }
    for (int i = v->length; i > ind; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

int erase(vec *v, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind >= v->length) return 0;
    for (int i = ind; i < v->length; i++) {
        v->data[i] = v->data[i + 1];
    }
    v->length -= 1;
    return 1;
}

void output(vec *v) {
    if (v == NULL) return ;
    printf("vec : [ ");
    for (int i = 0; i < v->length; i++) {
        i && cout << ", ";
        cout << v->data[i];
    }
    cout << "]" << endl;
}

void clear(vec *v) {
    if (v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}



int main() {
    #define MAX_N 20
    vec *v = init(4);
    srand(time(0));

    for (int i = 0; i < MAX_N; i++) {
        int op = rand() % 4;
        int val = rand() % 100;
        int ind = rand() % (v->length + 3) - 1; //  [-1, length + 2]
        switch (op) {
        case 0:
        case 1:
        case 2: 
                printf("insert %d at %d to vector = %d\n", val, ind, insert(v, ind, val));
                break;
        case 3:
                printf("erase a iterm at %d from vector = %d\n", ind, erase(v, ind));
                break;

        }
        output(v);
        cout << endl;
    }
    #undef MAX_N
    clear(v);
        
    return 0;
}

