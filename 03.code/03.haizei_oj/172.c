#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 20
void swap(char name[MAX_N], char temp[MAX_N]){

}
void insert(char name[MAX_N + 5], int n) {
//n个元素
    for (int i = 1; i < n; i++) {
        for (int j = i; j >= 1; j--) {
         if (strcmp(name[j],name [j - 1]) > 0) break;
          swap(name[j], name[j -1]);
            
        }
    }
}

int main()
{
    char name[10][MAX_N + 5] = {0};
    for (int i = 0; i < 10; i++) {
        scanf("%s", name[i]);
    }
    return 0;
}

