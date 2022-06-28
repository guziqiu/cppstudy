#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include <math.h>

#define NIL     (&__NIL)
#define COLOR_HL(a, b)      "\033[1;" #b "m" a "\033[0m"
#define GREEN_HL(a)         COLOR_HL(a, 32)
#define RED_HL(a)           COLOR_HL(a, 31)
#define BLUE_HL(a)          COLOR_HL(a, 34)
#define YELLOW_HL(a)        COLOR_HL(a, 33)
#define PURPLE_HL(a)        COLOR_HL(a, 35)
#define BOTTLEGREEN_HL(a)   COLOR_HL(a, 36)
#define MOVETO(x,y)         printf("\033[%d;%dH", (x), (y)) // 定位光标
#define CLEAR()             printf("\033[2J") // 清除屏幕


typedef struct Node {
    int data;
    int color;//0 red, 1 black 2double black
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {//空节点
    NIL->data = 0;
    NIL->color = 1;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int _data) {//初始化一个新节点
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = _data;
    root->color = 0;
    root->lchild = root->rchild = NIL;
    return root;
}

int has_red_child(Node *root) {//判断根节点的孩子结点是否有红色
    return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *left_rotate(Node *root) {
    //左旋，旧根节点的右孩子变成根节点，旧根节点的右孩子变成新根节点的左孩子，新根节点左孩子变成旧根节点
    Node *temp = root->rchild;//新根节点
    root->rchild = temp->lchild;//旧根节点的右孩子变成新根节点的左孩子
    temp->lchild = root;//新根节点左孩子是旧根节点
    return temp;
}

Node *right_rotate(Node *root) {
    //右旋，旧根节点左孩子变成新根节点，旧根节点的左孩子变成新根节点的右孩子，新根节点的右孩子变成旧根节点
    Node *temp = root->lchild;//新根节点为旧根节点的左孩子
    root->lchild = temp->rchild;//旧根节点的左孩子变成新根节点的右孩子
    temp->rchild = root;//新根节点的右孩子变成旧根节点
    return temp;
}

Node *insert_maintain(Node *root) {//插入新节点
    if (!has_red_child(root)) return root;//没有红色的孩子，不需要调整
    //没有判断是否发生双红冲突
    //不冲突的话，更改颜色不影响结果，如果发生冲突，更改颜色，解决冲突，root必定为黑色，因为孩子为红色
    int flag = 0;
    //分为两种情况 1.根节点的孩子中都是红色结点，2.根节点的孩子中有一个是红色
    // 1.根节点的孩子中都是红色结点
    if (root->lchild->color == 0 && root->rchild->color == 0 && 
    (has_red_child(root->lchild) || has_red_child(root->rchild))) goto insert_end;
    // 2.根节点的孩子中有一个是红色,使用flag标记两种情况
    // 2.1 根节点的左孩子是红色，且左孩子的子树中有红色结点
    if (root->lchild->color == 0 && has_red_child(root->lchild)) flag = 1;
    // 2.2 根结点的右孩子是红色，且右孩子的子树中有红色结点
    if (root->rchild->color == 0 && has_red_child(root->rchild)) flag = 2;
    if (flag == 0) return root;
    if (flag == 1) { 
        // 2.1 根节点的左孩子是红色，且左孩子的子树中有红色结点
        // 2.1.1 根节点的左孩子的右孩子为红色，为LR型，需要小左旋大右旋，
        // 2.1.2 根节点的左孩子的左孩子为红色，为LL型，需要大右旋，
        if (root->lchild->rchild->color == 0)//LR,需要小左旋，大右旋
            root->lchild = left_rotate(root->lchild);
        root = right_rotate(root);
    } else {
        // 2.2 根结点的右孩子是红色，且右孩子的子树中有红色结点
        // 2.2.1 根节点的右孩子的左孩子为红色，为RL型，需要小右旋大左旋，
        // 2.2.2 根节点的左孩子的左孩子为红色，为RR型，需要大右旋，
        if (root->rchild->lchild->color == 0) {//RL,需要小右旋，大左旋
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
insert_end:
    root->color = 0;//这里选择红色上浮，其实红色上浮，红色下沉均可，
    root->lchild->color = root->rchild->color = 1;
    return root;
}

Node *__insert(Node *root, int value) {
    if (root == NIL) return getNewNode(value);//根节点为空或者找到插入位置，插入新节点
    if (root->data == value) return root;//新插入的结点已经存在，不需要操作
    //在左子树中插入
    if (value < root->data) root->lchild = __insert(root->lchild, value);
    //在右子树中插入
    else root->rchild = __insert(root->rchild, value);
    //插入完之后进行平衡调整，然后 返回结果
    return insert_maintain(root);
}

Node *insert(Node *root, int data) {//插入
    root = __insert(root, data);
    root->color = 1;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {//删除结点时，站在父亲结点维持平衡
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;//没有双重黑，不调整
    // 有双重黑,
    // 1.1双重黑兄弟节点是红色，2种情况
    // 1.2双重黑的兄弟节点是黑色，并且，兄弟节点中有红色子节点，4种情况
    // 1.3双重黑的兄弟节点是黑色，兄弟节点下面的两个子节点也是黑色(即无红色)
    if (has_red_child(root)) {//兄弟节点是红色，通过旋转，转变成兄弟节点是黑色的情况
        int flag = 0;//1：右旋，2：左旋
        root->color = 0;//原根节点改红
        if (root->lchild->color == 0) {//1.1.1左兄弟为红色，右孩子为双黑结点，减掉一重黑色，右旋
            root->rchild->color -= 1;
            root = right_rotate(root);
            flag = 1;
        }
        else {//1.1.2右孩子为红色,左孩子为双黑结点，双黑结点减掉一重黑色，左旋
            root->lchild->color -= 1;
            root = left_rotate(root);
            flag = 2;
        }
        root->color = 1;//新根节点改黑
        if (flag == 1) root->rchild = erase_maintain(root->rchild);//若发生右旋，已经转变成兄弟结点为黑色的情况，递归检查右边是否平衡,
        else root->lchild = erase_maintain(root->lchild);//检查左边是否平衡
        return root;
    }
    if ((root->lchild->color == 2 && !has_red_child(root->rchild)) ||
        (root->rchild->color == 2 && !has_red_child(root->lchild)) ) {
    //1.3双重黑节点的兄弟节点是黑色，兄弟节点下面的两个子节点也是黑色(即无红色)
            root->lchild->color -= 1;//父节点增加一重黑色，双重黑与兄弟节点，分别减少一重黑色
            root->rchild->color -= 1;
            root->color += 1;
            return root;
    }
    //1.2双黑结点的兄弟节点是黑色，并且，兄弟节点中有红色子节点，有4种情况
    //R（兄弟）R（右子节点），左旋，新根结点改成原根结点的颜色，将新根的两个子节点，改成黑色
    //R（兄弟）L（左子节点）(红色)，先小右旋，对调新根与原根的颜色，转成RR(RL→RR)
    if (root->lchild->color == 2) {//左兄弟为双黑结点,RR,RL
        if (root->rchild->rchild->color != 0) {//RR
            //---- != root->rchild->rchild->color == 1(NIL)
            //------------不是红色
            root->rchild->color = 0;
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = 1;
        }
        root = left_rotate(root);//大左旋
        root->color = root->lchild->color;//新根结点改成原根结点的颜色
    } else {//右兄弟结点为双黑结点,LL,LR
        if (root->lchild->lchild->color != 0) {//LL
            root->lchild->color = 0;
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = 1;
        }
        root = right_rotate(root);//大右旋
        root->color = root->rchild->color;
    }
    root->lchild->color = root->rchild->color = 1;//
    return root;
}

Node *__erase(Node *root, int value) {
    //删除扥两种情况，删除度为2，和删除度为0和1
    if (root == NIL) return NIL;//没有要删除的值
    if (value < root->data) root->lchild = __erase(root->lchild, value);// 要删除的值在左子树中
    else if (value > root->data) root->rchild = __erase(root->rchild, value);// 要删除的值在右子树中
    else {// 找到要删除的值，有4种情况
        // 1.要删除的结点的孩子结点有空节点，即删除度为1或者度为0的结点
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            temp->color += root->color;
            // 1.1删除度为1的结点，分两种情况
            // 1.1.1若删除的根节点为红色，不会对红黑树的平衡产生影响，
            // 1.1.2若删除的根节点为黑色，他的子孩子一定为红色，如果为黑色，树不会平衡；删除根节点为黑色，temp->color = 2;产生双重黑结点
            // 1.2删除度为0的结点，分两种情况
            // 1.2.1删除度为0的红色结点，不会产生影响
            // 1.2.2删除度为0的黑色结点，temp = NIL,color=2,产生双黑结点
            free(root);//释放要删除的结点
            return temp;
        // 2.删除度为2的结点，转换成度为1或0的结点，转换的方法是和他的前驱结点交换 
        } else {
            Node *temp = predecessor(root);
            root->data = temp->data;
            root->lchild = __erase(root->lchild, temp->data);
        }
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int value) {//删除结点
    root = __erase(root, value);
    root->color = 1;//根节点为黑色
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void print(Node *root) {
    printf("%d %d %d %d\n",
        root->data, 
        root->color,
        root->lchild->data,
        root->rchild->data
    );
    return ;
}

void output(Node *root) {//中序遍历
    if (root == NIL) return ;
    output(root->lchild);
    print(root);
    output(root->rchild);
    return ;
}

void my_print(int flag, int bit, int dis, int x, int y, Node *root) {
    MOVETO(y, x);
    if (root->color == 1) {
        printf("%d\n", root->key);
    } else {
        printf(RED_HL("%-*d\n"), bit / 2, root->key);
    }
    if (flag == 1) {
        for (int i = 1; i <= dis; i++) {
            MOVETO(y - i, x + i * 2 - 1);
            printf("/\n");
        }
    } else if (flag == 2) {
        for (int i = 1; i <= dis; i++) {
            MOVETO(y - i, x - i * 2 + 1);
            printf("\\\n");
        }
    }
    return ;
}

void my_output(int flag, int bit, int dis, int x, int y, Node *root) {
    if (root == NIL) return ;
    my_print(flag, bit, dis, x, y, root);
    my_output(1, bit, dis / 2, x - dis - bit, y + dis / 2 + 1, root->lchild);
    my_output(2, bit, dis / 2, x + dis + bit, y + dis / 2 + 1, root->rchild);
    return ;
}

int getMaxwidth(Node *root) {
    if (root == NIL) return 0;
    while (root->rchild != NIL) root = root->rchild;
    int maxvalue = root->key;
    int bit = 0;
    while (maxvalue) {
        bit++;
        maxvalue /= 10;
    }
    return bit;
}




int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
            //case 3: output(root);
            case 3: {
                        CLEAR();
                        int bit = getMaxwidth(root);
                        my_output(0, bit, pow(2, root->h - 1), size.ws_col / 2, 1, root);
                    }
        }
        //output(root);
        //printf("------------\n");
    }


    return 0;
}
