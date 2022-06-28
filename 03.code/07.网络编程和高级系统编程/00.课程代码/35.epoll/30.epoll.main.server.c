#include "00.head.h"

#define MAX_EVENTS 10

int main(int argc, char **argv) {
    int server_listen, sockfd, port;
    int epollfd;
    struct epoll_event ev, *events;


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

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, server_listen, &ev) < 0) {
        perror("epoll_ctl");
        exit(1);
    }

    for (;;) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds < 0) {
            perror("epoll_wait");
            exit(1);
        }
        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == server_listen) {// 监听套接字
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                if ((sockfd = accept(server_listen, (struct sockaddr *)&client, &len)) < 0) {
                    perror("accept");
                    exit(1);
                }
                printf("<Login> : %s login ...\n", inet_ntoa(client.sin_addr));
                make_nonblock(sockfd);
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = sockfd;
                if ((epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev) < 0)) {
                    perror("epoll_ctl");

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
