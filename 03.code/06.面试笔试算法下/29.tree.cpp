#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define BASE 26

typedef struct Node {//字典树
    int flag;//标记当前结点是否独立成词
    struct Node *next[BASE];//假如只有26个字符串
} Node; 

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(p->next));//将p的子树的每一个值都初始化为0
    return p;
}

void insert(Node *p, const char *s) {
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (p->next[ind] == NULL)  p->next[ind] = getNewNode();
        p = p->next[ind];//向下走动一个结点，继续向下插入
    }
    p->flag = 1;
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

void output(Node *root, int k, char *s) {
    s[k] = 0;//字符串的最后一位为0
    if (root->flag) {//当前结点独立成词
        printf("%s\n", s);
    } 
    for (int i = 0; i < BASE; i++) {//遍历子节点
        if (root->next[i] == NULL) continue;//当前子节点为空
        //当前子节点不为空继续向下遍历
        s[k] = 'a' + i;
        output(root->next[i], k + 1, s);
    }
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
    output(root, 0, str);//深度优先遍历，当前字典树所在结点地址root，所在层数0， 字符串
    clear(root);
    return 0;
}

