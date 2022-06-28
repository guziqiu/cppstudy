#include <iostream>
#include <cstring>
using namespace std;

#define BASE 26

typedef struct Node {
    int flag;//是否独立成词，1是，0不是
    int tag[BASE];//记录每一条边是否被优化过：1字典树中的边，0：ac自动机中的边
    const char *str;
    struct Node *next[BASE];
    struct Node *fail;//等价关系指针
} Node;

int node_cnt = 0;//记录当前环境一共有多少个节点

Node *getNewNode() {
    node_cnt += 1;
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(p->next));
    p->fail = NULL;
    return p;
}

void insert(Node *root, const char *str) {//以字典树的形式插入
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        if (root->next[ind] == NULL) root->next[ind] = getNewNode();//要插入的新节点为空
        root->tag[ind] = 1;
        root = root->next[ind];
    }
    root->flag = 1;
    root->str = strdup(str);
    return ;
}

void build_ac(Node *root) {//建立ac自动机
    //用层序遍历的方式遍历，建立fail指针,层序遍历使用队列
    Node **q = (Node **)malloc(sizeof(Node *) * (node_cnt + 5));
    int head = 0, tail = 0;
    root->fail = NULL;//初始化根节点fail指针
    for (int i = 0; i < BASE; i++) {//初始化其他节点     
        if (root->next[i] == NULL) {
            root->next[i] = root;//根节点的next为空，默认指向根节点
            continue;
        }
        root->next[i]->fail = root;//根节点下面的第一层fail默认指向根节点
        q[tail++] = root->next[i];
    }
    while (head < tail) {//当队列不为空
        Node *p = q[head++];
        for (int i = 0; i < BASE; i++) {
            Node *c = p->next[i], *k = p->fail;
            if (c == NULL) {//当前节点没有子孩子
                p->next[i] = k->next[i];//没有子孩子，直接指向fail指向的节点
                continue;
            }
            while (k && k->next[i] == NULL) k = k->fail;//fail不为空且没有子孩子则直接指向fail
            if (k == NULL) k = root;
            if (k->next[i]) k = k->next[i];//k->next[i] != NULL,fail指向的节点那个找到和c空耳都爱美对应的节点
            c->fail = k;
            q[tail++] = c;//c节点压入队列
        }       
    }
    free(q);
    return ;
}

void match(Node *root, const char *text) {
    Node *p = root;
    Node *q;
    for (int i = 0; text[i]; i++) {
        int ind = text[i] -'a';
        p = p->next[ind];
        q = p;
        while (q) {
            if (q->flag == 1) printf("find : %s\n", q->str);
            q = q->fail;
        }
    }
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        if (root->tag[i]) clear(root->next[i]);//是字典树上的边
    }
    free(root);
    return ;
}


int main() {
    int n;
    char str[100];
    scanf("%d", &n);
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    build_ac(root);//建立AC自动机
    printf("build ac\n");
    scanf("%s", str);
    match(root, str);//匹配文本串
    clear(root);
    return 0;
}

