#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test2() {
    char string[11], str[10];
    int i;
    for(i = 0; i < 10; i++) {
        str[i] = 'a';
    }
    printf("%s\n", str);    
    strcpy(string, str);
    string[10] = '\0';
    printf("%s\n", string);    
}
int main() {
   test2();    
    return 0;
}

