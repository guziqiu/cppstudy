#include "wechat.h"
#include "head.h"

extern struct wechat_user *users;

void send_all(struct wechat_msg *msg)
{
        for (int i = 0; i < MAXUSERS; ++i)
        {
                if (users[i].isOnline && strcmp(users[i].name, msg->from))
                {
                        send(users[i].fd, msg, sizeof(msg), 0);
                }
        }
}

void *sub_reactor(void *arg)
{
        int subfd = *(int *)arg;
        DBG("sub reactor in sub readcot %d.\n", subfd);

        struct epoll_event ev;
        struct epoll_event events[MAXEVENTS];
        for (;;)
        {
                DBG("in subactor loop start\n");
                int nfds = epoll_wait(subfd, events, MAXEVENTS, -1);
                if (nfds < 0)
                {
                        DBG("sub reactor fd error, nfds=%d.\n", nfds);
                        continue;
                }
                for (int i = 0; i < nfds; ++i)
                {
                        DBG("int subreactor loop for each events\n");
                        int fd = events[i].data.fd;
                        struct wechat_msg msg;
                        bzero(&msg, sizeof(msg));
                        int ret = recv (fd, (void *)&msg, sizeof(msg), 0);
                        // if (ret <= 0 ) // && EAGAIN != errno)
                        // {
                        //         close(fd);
                        //         epoll_ctl(subfd, EPOLL_CTL_DEL, fd, NULL);
                        //         users[fd].isOnline = 0;
                        //         DBG("connection of %d on %d is closed.\n", fd, subds);
                        //         continue;
                        // }

                        if (ret != sizeof(msg))
                        {
                                DBG("sub reactor msg size err.\n");
                                continue;
                        }

                        if (msg.type & WECHAT_WALL)
                        {
                                DBG("%s : %s \n", msg.from, msg.msg);
                                send_all(&msg, );
                        }
                        else
                        {
                                DBG("err msg type %d.\n", msg.type);
                        }
                }
			sleep(30);
        }
}

int add_to_reactor(int epollfd, int fd)
{
        struct epoll_event ev;
        ev.data.fd = fd;
        ev.events = EPOLLIN;// | EPOLLET;
        // make_nonblock(fd);

        if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev) < 0)
        {
                return -1;
        }

        return 0;
}

void *client_recv(void *arg)
{
        int sockfd = *(int *)arg;

        struct wechat_msg msg;
        while (1)
        {
                DBG("IN client_recv\n");
                bzero(&msg, sizeof(msg));
                int ret = recv(sockfd, (void *)&msg, sizeof(msg), 0);
                if (ret <= 0)
                {
                        DBG("ERR server closed connection.\n");
                        perror("recv");
                        exit(1);
                }
                printf("%s : %s\n", msg.from, msg.msg);
        }
}