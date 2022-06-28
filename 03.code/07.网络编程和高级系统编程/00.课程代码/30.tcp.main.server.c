#include "00.head.h"

int main(int argc, char **argv) {
    int server_listen, sockfd, port;
    if (argc != 2) {
        fprintf(stderr, "Usage:%s port!\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);
    if ((server_listen = socket_create(port)) < 0) {//创建套接字
        perror("socket_create");
        exit(-1);
    }
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    while (1) {//用于等待接收数据
        if ((sockfd = accept(server_listen, (struct sockaddr *)&client, &len)) < 0) {
            perror("accept");//三次握手失败
            exit(1);
        }
        printf("<%s> is online\n", inet_ntoa(client.sin_addr));
        pid_t pid;
        if ((pid = fork()) < 0) {
            exit(-1);
        }
        if (pid == 0) {
            close(server_listen);
            while (1) {//
                char buff[512] = {0};
                char tobuff[1024] = {0};
                size_t ret = recv(sockfd, buff, sizeof(buff), 0);
                if (ret <= 0) {
                    printf("<%s> is offline\n", inet_ntoa(client.sin_addr));
                    perror("recv");
                    close(sockfd);
                    exit(1);
                }
                printf("recv <%s>: %s\n", inet_ntoa(client.sin_addr), buff);
                sprintf(tobuff, "I've recvd your message : %s!\n", buff);
                send(sockfd, tobuff, strlen(tobuff), 0);//发送给客户端
            }
        } else {
            printf("<Parent> : 什么也不gan。。。\n");
            close(sockfd);//
        }
    }

    
    return 0;
}

