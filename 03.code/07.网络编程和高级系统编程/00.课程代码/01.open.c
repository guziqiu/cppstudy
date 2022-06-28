#include "00.head.h"


int main() {
    int fd;
    char buff[512] = {0};
    ssize_t nread;
    if ((fd = open("./a.txt", O_CREAT | O_RDONLY)) < 0) {
        perror("open");
        exit(1);
    }
    while ((nread = read(fd, buff, sizeof(buff))) > 0) {//从fd读入到buff，每次的大小为buff的大小 
        printf("read %ld\n buffer =  %s", nread, buff);
        memset(buff, 0, sizeof(buff));
    }
    close(fd);
    return 0;
}

