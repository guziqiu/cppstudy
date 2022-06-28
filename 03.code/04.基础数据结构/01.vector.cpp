#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a,b) "\033[" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)


//结构定义    
typedef struct Vector {
    int *data;//存储数据，记录连续开辟的存储空间的首地址
    int size, length;//
} Vec;
    
Vec *init(int n) {
     Vec *v = (Vec *)malloc(sizeof(Vec));//动态开辟空间
     v->data = (int *)malloc(sizeof(int) * n);//data指向开辟空间的首地址
     v->size = n;//
     v->length = 0;
        return v;
}

int expand(Vec *v) {
    //malloc 仅开辟空间，calloc 开辟空间并且初始化，清空原来的值，realloc 重新划分空间
    //realloc(地址,字节数)，返回值为新开辟空间的首地址，
    //首先会在原来地址的后面开辟一倍的地址，并且返回原来的首地址，
    //如果后面的取件无法扩建，找一个其他地方，为原来的两倍，将原来的内容拷贝到新开辟的空间，返回首地址
    //不一定开辟成功，降低需求开1/2，如果无法开辟空间返回值为NULL,
    int extr_size = v->size;
    int *p;
    while (extr_size) {
        p = (int *)realloc(v->data, sizeof(int) * (v->size + extr_size));//开辟原来的2倍
        if (p) break;//开辟空间成功
        extr_size >>= 1;//开辟空间失败,降低需求，开辟1/2
    }
    if (extr_size == 0) return 0;
    v->data = p;
    v->size += extr_size;
    return 1;
}

//插入
int insert(Vec *v, int value, int index) {
    //在v中的index位置插入值value
    if (v == NULL) return 0;
    if (index < 0 || index > v->length) return 0;//插入位置不合法
    if (v->length == v->size) {//顺序表已满,扩容
        if (!expand(v)) return 0;
        printf(GREEN("success to expand! the Vector size is %d\n"), v->size);
    }
    for (int i = v->length; i > index; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[index] = value;
    v->length +=1;
    return 1;
}

//删除顺序表中第index位置的值
int erase(Vec *v, int index) {
    if (v == NULL) return 0;
    if (index < 0 || index >= v->length) return 0;//插入位置不合法
    for (int i = index + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i]; 
    }
    v->length -= 1;
    return 1;
}
   
void clear(Vec *v) {
    if(v == NULL) return ;//如果v为空
    free(v->data);
    free(v);//释放malloc动态申请的内存
       return ;
}

//输出线性表
void output(Vec *v) {
    if (v == NULL) return ;
    printf("Vector : [");
    for (int i = 0; i < v->length; i++) {
        i && printf(",");
        printf("%d", v->data[i]);
    }
    printf("]\n");
    return ;
}


int main() {
    srand(time(0));
    #define max_op 20
    Vec *v = init(2);
    for (int i = 0; i < max_op; i++) {
        int value = rand() % 100;
        int index = rand() % (v->length + 3) -1;//index = [-1, length + 2],测试用例
        int op = rand() % 4;
        switch (op) {//012插入3删除
        case 1:
        case 2:
        case 0:
            printf("insert %d at %d to Vector = %d\n", value, index, insert(v, value, index));
            break;
        case 3:
            printf("erase a iterm at %d from Vector = %d\n", index, erase(v, index));
            break;
        }
        output(v);
        printf("\n");
    }
    clear(v);
    #undef max_op

    return 0;
}
