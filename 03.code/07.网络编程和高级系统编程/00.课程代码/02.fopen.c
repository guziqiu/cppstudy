#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
   
    FILE *fp = NULL;
    if ((fp = fopen("./b.txt", "r")) == NULL) {
        perror("fopen");
        exit(1);
    }
    while (1) {
        char buff[512] = {0};
        size_t nread = fread(buff, 1, sizeof(buff), fp);
        printf("%s", buff);
        if (nread <= 0) break;
    }
    fclose(fp);

    return 0;
}

