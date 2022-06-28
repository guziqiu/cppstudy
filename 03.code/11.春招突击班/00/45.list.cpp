#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node head; // 虚拟头节点
    int length;
} List;


Node *getNewNode(int);
List *init_list();
void clear_node(Node *);
int clear(List *);
int insert(List *, int, int);
int erase(List *, int);
void output(List *);
void reverse(List *); // 原地翻转


int main() {

    srand(time(0));
#define MAX_OP 20
    List *l  = init_list();
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        int ind = rand() % (l->length + 3) - 1;
        int op = rand() % 5;
        switch (op) {
        case 0:
        case 1:
        case 2:
            printf("insert %d at %d to list = %d \n", val, ind, insert(l, ind, val));
            break;
        case 3:
            printf("erase a iterm at %d from list = %d\n", ind, erase(l, ind));
            break;
        case 4:
            printf("reverse the list \n"), reverse(l);
            //output(l);
            break;
        }
        output(l), cout << endl;
    }
    #undef  MAX_OP
    clear(l);

    
    return 0;
}

void output(List *l) {
    printf("List(%d) : ", l->length);
    for (Node *p = l->head.next; p != NULL; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
    return ;
}

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

List *init_list() {
    List *list = (List *)malloc(sizeof(List));
    list->head.next = NULL;
    list->length = 0;
    return list;
}


void clear_node(Node *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

int clear(List *list) {
    if (list == NULL) return 0;
    Node *p = list->head.next, *q;
    while (p) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(list);
    return 1;
}


int insert(List *list, int ind, int val) {
    if (list == NULL) return 0;
    if (ind < 0 || ind > list->length) return 0;

    Node *p = &(list->head);
    Node *node = getNewNode(val);

    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    list->length += 1;
    return 1;
}

int erase(List *list, int ind) {
    if (list == NULL) return 0;
    if (ind < 0 || ind >= list->length) return 0;
    Node *p = &(list->head);
    Node *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    clear_node(q);
    list->length -= 1;
    return 1;
}

void reverse(List *l) {
    if (l == NULL) return ;
    Node *p = l->head.next;
    Node *q;
    l->head.next = NULL;;
    while (p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return ;
}






