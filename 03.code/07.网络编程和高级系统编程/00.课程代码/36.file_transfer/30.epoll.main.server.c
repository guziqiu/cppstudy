#include "00.head.h"

#define MAX_EVENTS 10
#define MAX_CLIENTS 100 // 最大客户数

// 收发文件
//
struct Client {
    char name[20];
    int fd;
    int online;
};


int main(int argc, char **argv) {
    int server_listen, sockfd, port;
    int epollfd;
    struct epoll_event ev, events[MAX_EVENTS];


    if (argc != 2) {
        fprintf(stderr, "Usage:%s port!\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);
    if ((server_listen = socket_create(port)) < 0) {//创建套接字
        perror("socket_create");
        exit(-1);
    }

    if ((epollfd = epoll_create(1) < 0)) {
        perror("epoll_create");
        exit(1);
    }
    
    ev.events = EPOLLIN;
    ev.data.fd = server_listen;

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, server_listen, &ev) == 0) {
        perror("epoll_ctl");
        printf("..1\n");
        exit(1);
    }



    struct Client *users = (struct Client *)malloc(sizeof(struct Client) * MAX_CLIENTS);//结构体数组 用户

    for (;;) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds < 0) {
            perror("epoll_wait");
            exit(1);
        }
        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == server_listen) {// 监听套接字
                struct sockaddr_in client;
                char name[20] = {0};
                socklen_t len = sizeof(client);
                if ((sockfd = accept(server_listen, (struct sockaddr *)&client, &len)) < 0) {
                    perror("accept");
                    exit(1);
                }
                printf("<Login> : %s login ...\n", inet_ntoa(client.sin_addr));
                make_nonblock(sockfd);

                // 登录
                if (recv_str_nonblock(sockfd, name, sizeof(name), 10000) != 0) {
                    printf("<LoginError> : %s did not send his name... delete...\n", inet_ntoa(client.sin_addr));
                    close(sockfd);
                    continue;
                    //exit(1);
                }

                send(sockfd, "welcome!", sizeof("welcome!"), 0);


                users[sockfd].fd = sockfd;
                strcpy(users[sockfd].name, name);
                users[sockfd].online = 1;
                printf("<LoginSuccsee> : %s login on %s ... \n\n", name, inet_ntoa(client.sin_addr));


                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = sockfd;
                if ((epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev) < 0)) {
                    perror("epoll_ctl");
                    printf("..1\n");
                    exit(1);

                }
            } else {
                //do_use_fd(events[i].data.fd);
                char buff[1024] = {0};
                int rsize = 0, fd = events[i].data.fd;
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                getpeername(fd, (struct sockaddr *) &client, &len);
                if ((rsize = recv(fd, buff, sizeof(buff), 0)) <= 0) {
                    printf("<Logout> : %s logout .. \n", inet_ntoa(client.sin_addr));
                    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, NULL);
                    close(fd);
                } else {
                    printf("<%s Message> : %s \n", inet_ntoa(client.sin_addr), buff);
                    send(fd, buff, strlen(buff), 0);
                }
            }
        }


    }






    
    return 0;
}
