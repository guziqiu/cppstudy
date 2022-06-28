#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32) 

//结构定义
typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

typedef struct List {
    ListNode head;//虚拟头结点
    int length;
} List;

ListNode *createNewNode(int);//初始化结点
List *createLinkList();//初始化链表
void clear_node(ListNode *);//释放结点
void clear(List *);//释放链表
int insert(List *, int, int);//插入
int erase(List *, int);//删除
void output(List *);//打印链表
void reverse(List *);

int main()
{
    srand(time(0));
    #define max_op 20
    List *list = createLinkList();
    for (int i = 0; i < max_op; i++) {
        int value = rand() % 100;
        int index = rand() % (list->length + 3) - 1;
        int op = rand() % 5;
        switch (op) {
        case 0:
        case 1:
        case 2:{
            printf("insert %d at  %d to list = %d\n", value, index, insert(list, index, value));
               } 
            break;
        case 3:
            printf("earse a iterm at %d from list = %d\n", index, erase(list, index));
            break;
        case 4:{
            printf(GREEN("reverse the list!\n"));
            reverse(list);
             }break;
        }
        output(list);
        printf("\n");
    }
    #undef max_op
    clear(list);
    return 0;
}

ListNode *createNewNode(int value){
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = value;
    node->next = NULL;
    return node;
}

List *createLinkList() {
    List *list = (List *)malloc(sizeof(List));
    list->head.next = NULL;
    list->length = 0;
    return list;
}

int insert(List *list, int index, int value) {
    if (list == NULL) return 0;
    if (index < 0 || index > list->length) return 0;
    ListNode *p = &(list->head);//指向头结点
    ListNode *node = createNewNode(value);//初始化结点，准备插入链表中
    while (index--) p = p->next;
    node->next = p->next;
    p->next = node;
    list->length += 1;
    return 1;
}

int erase(List *list, int index) {
    if (list == NULL) return 0;
    if (index < 0 || index >= list->length) return 0;
    ListNode *p = &(list->head);
    ListNode *delete_node;
    while (index--) p = p->next;
    delete_node = p->next;
    p->next = delete_node->next;
    free(delete_node);
    list->length -=1;
    return 1;
}

void reverse(List *list) {
    if (list == NULL) return ;
    ListNode *p = list->head.next;
    ListNode *q;
    list->head.next = NULL;
    while (p) {
        q = p->next;
        p->next = list->head.next;
        list->head.next = p;
        p = q;
    }
    return ;
}

void output(List *list) {
    if (list == NULL) return ;
    printf("List(%d) = [", list->length);
    for (ListNode *p = list->head.next; p; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL]\n");
    return ;
}

void clear_node(ListNode *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}
void clear(List *list) {
    if(list == NULL) return ;
    ListNode *delete_node = list->head.next;
    ListNode *temp;
    while (delete_node) {
        temp = delete_node->next;
        free(delete_node);
        delete_node = temp;
    }
    free(list);
}







