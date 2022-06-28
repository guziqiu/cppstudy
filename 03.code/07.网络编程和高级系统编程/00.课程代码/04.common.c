
#include "00.head.h"


int make_nonblock(int fd) {//设置非阻塞
    //fcntl(fd, F_SETFL, O_NONBLOCK);
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {//获得文件状态标记
        return -1;
    }
    flag |= O_NONBLOCK;//flag = O_NONBLOCK,以非阻塞方式打开，在原先flag的基础加上非阻塞方式
    return fcntl(fd, F_SETFL, flag);//设置文件状态标记
}

int make_block(int fd) {//设置阻塞方式
    //fcntl(fd, F_SETFL, O_NONBLOCK);
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {//获得文件状态标记flag
        return -1;
    }
    flag &= ~O_NONBLOCK;//flag = O_NONBLOCK,以非阻塞方式打开，设置非阻塞方式
    return fcntl(fd, F_SETFL, flag);//设置文件状态标记
}






