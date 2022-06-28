#include "00.head.h"


int socket_create(int port) {//创建套接字
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {//创建套接字,ipv4，socker流
        return -1;//有太多的文件
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;//协议组 IPV4
    addr.sin_port = htons(port);//端口，主机字节序转换成本地字节序
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");//
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {//绑定
        return -1;//端口被占用
    }

    if (listen(sockfd, 20) < 0) {// 
        return -1;
    }
    return sockfd;
}



