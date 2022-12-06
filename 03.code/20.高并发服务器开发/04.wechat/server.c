#include "head.h"
#include "wechat_ui.h"

extern struct wechat_user *users;
extern const char *config;
// gcc ./server.c -std=c99 -I ./common -I ./  ./common/common.c ./wechat.c -I ./common ./common/wechat_ui.c -D _D -lpthread -lncursesw -o server
WINDOW *msg_win, *sub_msg_win, *info_win, *sub_info_win, *input_win, *sub_input_win;

int main(int argc, char **argv)
{
	int opt, port;

	while ((opt = getopt(argc, argv, "p:")) != -1)
	{
		switch (opt)
		{
		case 'p':
			port = atoi(optarg);
			break;

		default:
			fprintf(stderr, "Usage : %s -p port.\n", argv[0]);
			exit(-1);
			break;
		}
	}

	if (access(config, R_OK))
	{
		fprintf(stderr, "err config file error!\n");
	}

	if (!port)
	{
		// read conf
		port = get_conf_val_int(config, "SERVER_PORT");
		DBG("port = %d\n", port);
	}

#ifdef UI
	setlocale(LC_ALL, "");
	init_ui();
#endif

	int server_listen;
	int sockfd, epollfd, subefd1, subefd2;
	DBG("config file read sucess\n");
	if ((server_listen = socket_create(port)) < 0)
	{
		perror("socket_create");
		exit(-1);
	}

	DBG("server_listen is listening on port : %d\n", port);

	struct itimerval itv;
	itv.it_interval.tv_sec = 2;
	itv.it_interval.tv_usec = 0;
	itv.it_value.tv_sec = 1;
	itv.it_value.tv_usec = 0;
	setitimer(ITIMER_REAL, &itv, NULL);
	signal(SIGALRM, heart_beat);

	// sleep(20); 

	users = (struct wechat_user *)calloc(MAXUSERS, sizeof(struct wechat_user));

	if ((epollfd = epoll_create(1)) < 0) // 主反应堆
	{
		perror("epoll_create");
		exit(-1);
	}

	if ((subefd1 = epoll_create(1)) < 0)
	{
		perror("epoll_create");
		exit(-1);
	}

	if ((subefd2 = epoll_create(1)) < 0)
	{
		perror("epoll_create");
		exit(-1);
	}

	setfd(epollfd, subefd1, subefd2);

	DBG("main reactor and two sub reactors created.\n");

	pthread_t tid1, tid2, heart_tid;
	DBG("Two sub reactor threads created\n");
	pthread_create(&tid1, NULL, sub_reactor, (void *)&subefd1);
	pthread_create(&tid2, NULL, sub_reactor, (void *)&subefd2);
	pthread_create(&heart_tid, NULL, heart_beat, NULL);

	struct epoll_event events[MAXEVENTS];
	struct epoll_event ev;

	ev.data.fd = server_listen;
	ev.events = EPOLLIN;

	epoll_ctl(epollfd, EPOLL_CTL_ADD, server_listen, &ev);

	for (;;)
	{
		sigset_t sigset;
		sigemptyset(&sigset);
		sigaddset(&sigset, SIGALRM);

		// 判断文件描述符是否就绪
		int nfds = epoll_pwait(epollfd, events, MAXEVENTS, -1, &sigset);

		if (nfds < 0)
		{
			perror("epoll_wait");
			exit(-1);
		}

		printf("nfds:%d\n", nfds);
		for (int i = 0; i < nfds; ++i)
		{
			int fd = events[i].data.fd;
			if (fd == server_listen && events[i].events & EPOLLIN)
			{
				if ((sockfd = accept(server_listen, NULL, NULL)) < 0)
				{
					perror("accept");
					exit(-1);
				}

				ev.data.fd = sockfd;
				ev.events = EPOLLIN;
				epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev);
			}
			else
			{
				// 收数据 验证数据 完成具体的操作
				struct wechat_msg msg;
				bzero(&msg, sizeof(msg));
				int ret = recv(fd, (void *)&msg, sizeof(msg), 0);
				if (ret <= 0)
				{
					// 接收有问题，关掉
					epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL);
					close(fd);
					continue;
				}

				if (ret != sizeof(msg))
				{
					DBG("message %s size %ld error: %d.\n", msg.msg, sizeof(msg), ret);
					perror("recv");
					continue;
				}

				if (msg.type & WECHAT_SIGNUP)
				{
					// 注册用户 更新用户信息到文件中 判断是否可以注册
					msg.type = WECHAT_ACK;
					send(fd, (void *)&msg, sizeof(msg), 0);
				}
				else if (msg.type & WECHAT_SININ)
				{
					// 登录 判断密码是否正确，验证用户是否重复登录
					// 从反应堆
					wclear(sub_input_win);
					msg.type = WECHAT_ACK;
					send(fd, (void *)&msg, sizeof(msg), 0);
					strcpy(msg.msg, "login sucess 登录成功!\n");

					show_msg(&msg);
					strcpy(users[fd].name, msg.from);
					users[fd].fd = fd;
					users[fd].isOnline = 5;
					users[fd].sex = msg.sex;

					int which = msg.sex == 1 ? subefd1 : subefd2;
					epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL); // 从反应堆添加文件描述符时，将文件描述符从主反应堆删除
					add_to_reactor(which, fd);
				}
				// else if (msg.type & WECHAT_SIGNOUT)
				// {
				// }
				// else
				// {
				// 	// 报文数据有误
				// }
			}
		}
	}

	sleep(1);

	return 0;
}

// gcc server.c -std=c99 -I ../common -I ../ ../common/common.c ../wechat.c -D _D -lpthread  -o server
