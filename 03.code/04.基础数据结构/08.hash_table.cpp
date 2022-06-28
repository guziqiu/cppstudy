#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//对字符串建立哈希表：BKDRHash
//冲突处理方法：拉链法
//结构定义

typedef struct Node {
    char *str;
    struct Node *next;
} Node;//链表结点

typedef struct HashTable {//哈希表结构定义
    Node **data;//存Node*
    int size;
} HashTable;

Node *init_node(Node *str, Node *head) {//初始化结点,将str插入到以head为头结点的链表中,头插法,所有的新节点都会插入到头部
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);//符串拷贝
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {//初始化哈希表，大小n
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;//哈希表的利用率一定小于100%，一般为50%~90%
    h->data = (Node **)calloc(h->size, sizeof(Node *));
    return h;
}

int BKDRHash(char *str) {
    int seed = 31;//初始化映射种子
    int hash = 0;
    for (int i = 0; str[i]; i++) hash = hash * seed + str[i];
    return hash & 0x7fffffff;//防止hash变成负数，将符号位变成正数
}

int insert(HashTable *h, char *str) {//
    int hash = BKDRHash(str);//将字符串映射成整型数组下表
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    return 1;
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);
        p = q;
    }
    return ;
}

void clear_hashtable(HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) {
        clear_node(h->data[i]);
    }
    free(h->data);
    free(h);
    return ;
}

int main() {
    int op;
    #define max_n 100
    char str[max_n + 5] = {0};
    HashTable *h = init_hashtable(max_n + 5);
    while (~scanf("%d%s", &op, str)) {
        switch(op) {
        case 0:
            printf("insert %s to HashTable\n", str);
            insert(h, str);
            break;
        case 1:
            printf("search %s fromm HashTable result = %d \n", str, search(h, str));
            break;
        }
        
    }
    #undef max_n
    clear_hashtable(h);



    return 0;
}

