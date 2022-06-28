#include <iostream>
#include <cstring>
using namespace std;

#define BASE 26
#define MSG_LEVEL 1
#define DEBUG_LEVEL 1
#define INFO_LEVEL 2

#define LOG(level, frm, args...) {\
    if (level >= MSG_LEVEL) {\
        printf(frm, ##args);\
    }\
}

#define LOG_DEBUG(args...) LOG(DEBUG_LEVEL, args);
#define LOG_INFO(args...) LOG(INFO_LEVEL, args);



typedef struct Node {//字典树
    int flag;
    struct Node *next[BASE];//存储26个英文字符的字典树
} Node;

typedef struct DANode {//双数组字典树结构
    int base, check, fail;//fail用于在双数组字典树中建立AC自动机
} DANode;//

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(p->next));
    return p;
}

inline int code(char c) { return c - 'a'; }

int insert(Node *root, const char *str) {//在字典树中插入
    int cnt = 0;
    Node *p = root;//指向当前插入字符串的位置
    for (int i = 0; str[i]; i++) {
        int ind = code(str[i]);
        if (p->next[ind] == NULL) {//相关子节点为空
            cnt++;
            p->next[ind] = getNewNode();
        }
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;//返回本次插入str时一共生成几个新节点
}

int get_base_value(Node *root, DANode *tree, int ind) {
    int base = 1, flag;
    do {
        base += 1;
        flag = 1;
        for (int i = 0; i < BASE && flag; i++) {
            if (root->next[i] == NULL) continue;
            if (tree[base + i].check) flag = 0;//如果存在check值，说明base值已经被占用
        }
    } while (flag == 0);
    return base;
}

int transform_double_array_trie(Node *root, DANode *tree, int ind) {
    //字典树转换成双数组字典树，双数组字典树存储在tree中，ind：根节点在双数组字典树中的下标
    //返回最大的下标值
    if (root == NULL) return 0;
    if (root->flag) tree[ind].check = -tree[ind].check;//当前节点独立成词
    int base = get_base_value(root, tree, ind);//获得当前节点的base值
    tree[ind].base = base;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree[base + i].check = ind;//子节点check存储父节点下标
    }
    int max_ind = ind;
    for (int i = 0; i < BASE; i++) {//依次确认每一个子节点是base值
        int temp = transform_double_array_trie(root->next[i], tree, base + i);
        if (temp > max_ind) max_ind = temp;
    }
    return max_ind;//返回最大下标
}

void dump_double_array_tree(DANode *tree, int n) {
    LOG_INFO("%d\n", n);
    for (int i = 0; i <= n; i++) {
        LOG_INFO("%d %d %d\n", tree[i].base, tree[i].check, tree[i]. fail);
    }
    return ;
}

void clear_trie(Node *root) {
    if (root == NULL)  return ;
    for (int i = 0; i < BASE; i++) {
        clear_trie(root->next[i]);
    }
    free(root);
    return ;
}

void build_ac_base_double_array_trie(DANode *tree, int max_ind) {
    int *que = (int *)malloc(sizeof(int) * (max_ind + 5));
    int head, tail;
    head = tail = 0;
    tree[1].fail = 0;
    for (int i = 0; i < BASE; i++) {
        int child_ind = tree[1].base + i;
        if (abs(tree[child_ind].check) != 1) continue;//第i个节点有子孩子
        tree[child_ind].fail = 1;//fail节点指向子孩子
        que[tail++] = child_ind;
    }
    while (head < tail) {
        int p = que[head++];//当前节点不为空，取出当前节点
        for (int i = 0; i < BASE; i++) {
            int c = tree[p].base + i, k = tree[p].fail;
            if (abs(tree[c].check) != p) continue;
            while (k && tree[tree[k].base + i].check != k) k = tree[k].fail;//k节点下面没有第k个子孩子
            if (k == 0) k = 1;
            if (abs(tree[tree[k].base + i].check) == k) k = tree[k].base + i;
            tree[c].fail = k;//初始化c节点的fail值
            que[tail++] = c;
        }
    }
    free(que);
    return ;
}


int main() {
    int n, cnt =  1;//字典树中一共有cnt个节点
    char str[1000];
    scanf("%d", &n);//读入n个单词
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);//每次读入一个单词插入字典树中
        cnt += insert(root, str);
    }
    //将字典树转换成双数组字典树
    size_t tree_size = sizeof(DANode) * (cnt * BASE); 
    DANode *tree = (DANode *)malloc(tree_size);
    memset(tree, 0, tree_size);
    int max_ind = transform_double_array_trie(root, tree, 1);
    size_t s1 = cnt * sizeof(Node);
    size_t s2 = max_ind * sizeof(DANode);
    LOG_DEBUG("trie(%lu Byte), double array trie(%lu, Byte)\n", s1, s2);
    LOG_DEBUG("rate : %.2lf\n", 1.0 * s2 / s1);
    for (int i = 0; i <= max_ind; i++) {
        LOG_DEBUG("(%d | %d, %d)\t", i, tree[i].base, tree[i].check);
        if ((i + 1 ) % 5 == 0) LOG_DEBUG("\n");
    }
    LOG_DEBUG("\n");
    //将字典树双数组输入到文件中去
    build_ac_base_double_array_trie(tree, max_ind);
    dump_double_array_tree(tree, max_ind);
    free(tree);
    clear_trie(root);

    return 0;
}

