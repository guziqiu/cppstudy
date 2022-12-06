#include "head.h"

extern struct wechat_user *users;
int *s_epollfd, *s_subefd1, *s_subefd2;
void setfd(int epollfd, int subefd1, int subefd2)
{
	s_epollfd = &epollfd;
	s_subefd1 = &subefd1;
	s_subefd2 = &subefd2;
}


void heart_beat(int signum)
{
	struct wechat_msg msg;
	msg.type = WECHAT_HEART;
	
	DBG(GREEN"SIGALRM\n"NONE);
	for (int i = 0; i < MAXUSERS; ++i)
	{
		if (users[i].isOnline)
		{
			send(users[i].fd, (void *)&msg, sizeof(struct wechat_msg), 0);
			--users[i].isOnline;
			if (users[i].isOnline == 0)
			{
				int tmp_fd = users[i].sex ? *s_subefd1 : *s_subefd2;
				epoll_ctl(tmp_fd, EPOLL_CTL_DEL, users[i].fd, NULL);
				close(users[i].fd);
				DBG(RED"<heart beat err>"NONE"%s is removed because if heart beat error\n", users[i].name);
			}
		}
	}
}

void send_all(struct wechat_msg *msg)
{
	DBG("msg [from=%s, msg=%s]\n", msg->from, msg->msg);
	for (int i = 0; i < MAXUSERS; ++i)
	{
		// DBG("--> %d %s %d<--\n", i, users[i].name, users[i].isOnline);
		if (users[i].isOnline)
		{
			send(users[i].fd, msg, sizeof(struct wechat_msg), 0);
		}
	}
}

void send_all_not_me(struct wechat_msg *msg)
{
	DBG("msg [from=%s, msg=%s]\n", msg->from, msg->msg);
	for (int i = 0; i < MAXUSERS; ++i)
	{
		DBG("--> %d %s <--\n", i, users[i].name);
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

		sigset_t sigset;
		sigemptyset(&sigset);
		sigaddset(&sigset, SIGALRM);
	
		int nfds = epoll_pwait(subfd, events, MAXEVENTS, -1, &sigset);
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
			int ret = recv(fd, (void *)&msg, sizeof(msg), 0);
			if (ret < 0 && !(EAGAIN & errno))
			{
				close(fd);
				epoll_ctl(subfd, EPOLL_CTL_DEL, fd, NULL);
				users[fd].isOnline = 0;
				DBG("connection of %d on %d is closed.\n", fd, subfd);
				continue;
			}

			if (ret != sizeof(msg))
			{
				DBG("sub reactor msg size err.\n");
				continue;
			}

			users[fd].isOnline = 5;
			if (msg.type & WECHAT_WALL)
			{
				show_msg(&msg);
				DBG("%s : %s \n", msg.from, msg.msg);
				send_all(&msg);
			}
			else if (msg.type & WECHAT_HEART && msg.type & WECHAT_ACK)
			{
				DBG(RED"ack for ❤ \n"NONE);
			}
			else
			{
				DBG("err msg type %d.\n", msg.type);
			}
		}

		sleep(1);
	}
}

int add_to_reactor(int epollfd, int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	ev.events = EPOLLIN | EPOLLET;
	make_nonblock(fd);

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
		bzero(&msg, sizeof(msg));
		int ret = recv(sockfd, (void *)&msg, sizeof(msg), 0);
		if (ret < 0)
		{
			DBG("ERR server closed connection.\n");
			perror("recv");
			exit(1);
		}
		if (msg.type & WECHAT_HEART)
		{
			strcpy(msg.msg, "--> ❤");
			show_msg(&msg);

			struct wechat_msg ack;
			ack.type = WECHAT_ACK | WECHAT_HEART; // 表明是对心跳包的确认
			send(sockfd, (void *)&ack, sizeof(ack), 0);
		}
		else
		{
			show_msg(&msg);
		}
	}
}