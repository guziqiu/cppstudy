#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int color;//0 red, 1 black 2double black
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->data = 0;
    NIL->color = 1;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int _data) {
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = _data;
    root->color = 0;
    root->lchild = root->rchild = NIL;
    return root;
}

int has_red_child(Node *root) {//判断根节点是否有红色的孩子结点
    return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;//没有红色的孩子，不需要调整
    int flag = 0;
    if (root->lchild->color == 0 && root->rchild->color == 0) goto insert_end;
    if (root->lchild->color == 0 && has_red_child(root->lchild)) flag = 1;
    if (root->rchild->color == 0 && has_red_child(root->rchild)) flag = 2;
    if (flag == 0) return root;
    if (flag == 1) {
        if (root->lchild->rchild->color == 0)//LR,需要小左旋，大右旋
            root->lchild = left_rotate(root->lchild);
        root = right_rotate(root);
    } else {//
        if (root->rchild->lchild->color == 0) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
insert_end:
    root->color = 0;//红色上浮，红色下沉也可
    root->lchild->color = root->rchild->color = 1;
    return root;
}

Node *__insert(Node *root, int value) {
    if (root == NIL) return getNewNode(value);
    if (root->data == value) return root;
    if (value < root->data) root->lchild = __insert(root->lchild, value);
    else root->rchild = __insert(root->rchild, value);
    return insert_maintain(root);
}

Node *insert(Node *root, int data) {
    root = __insert(root, data);
    root->color = 1;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;
    if (has_red_child(root)) {//兄弟节点是红色，通过旋转，转变成兄弟节点是黑色的情况
        int flag = 0;//1：右旋，2：左旋
        root->color = 0;//原根节点改红
        if (root->lchild->color == 0) {//左孩子为红色，右孩子为双黑结点，减掉一重黑色，右旋
            root->rchild->color -= 1;
            root = right_rotate(root);
            flag = 1;
        }
        else {//右孩子为红色,左孩子为双黑结点，双黑结点减掉一重黑色，左旋
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
        //双重黑节点的兄弟节点是黑色，兄弟节点下面的两个子节点也是黑色(即无红色)
            root->lchild->color -= 1;//父节点增加一重黑色，双重黑与兄弟节点，分别减少一重黑色   
            root->rchild->color -= 1;                                                       
            root->color += 1;                                                                      
            return root;                                                                    
    }   
    //双黑结点的兄弟节点是黑色，并且，兄弟节点中有红色子节点 
    //R（兄弟）R（右子节点），左旋，新根结点改成原根结点的颜色，将新根的两个子节点，改成黑色
    //R（兄弟）L（左子节点）(红色)，先小右旋，对调新根与原根的颜色，转成RR(RL→RR)
    if (root->lchild->color == 2) {//左兄弟为双黑结点
        if (root->rchild->rchild->color != 0) {//---- != root->rchild->rchild->color == 1(NIL)
            //------------不是红色
            root->rchild->color = 0;
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = 1;
        }
        root = left_rotate(root);//大左旋
        root->color = root->lchild->color;//新根结点改成原根结点的颜色
    } else {//右兄弟结点为双黑结点
        if (root->lchild->lchild->color != 0) {
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
    if (root == NIL) return NIL;
    if (value < root->data) root->lchild = __erase(root->lchild, value);
    else if (value > root->data) root->rchild = __erase(root->rchild, value);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            temp->color += root->color;
            //若根节点为红色，值不变，若为黑色，子孩子一定为红色，
            //temp == NIL，root度为0，则，color=2,产生双黑结点
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->data = temp->data;
            root->lchild = __erase(root->lchild, temp->data);
        }
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int value) {
    root = __erase(root, value);
    root->color = 1;
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
    printf("(%d| %d, %d, %d)\n",
        root->color, root->data,
        root->lchild->data,
        root->rchild->data
    );
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
            case 3: output(root);
        }
        output(root);
        printf("------------\n");
    }


    return 0;
}

