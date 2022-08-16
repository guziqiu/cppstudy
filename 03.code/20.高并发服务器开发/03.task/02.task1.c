#include "00.head.h"

#include "thread_pool.h"

#define QUEUESIZE 1000
#define INS 3
// #define INS 4
#define MAXEVENTS 5

#define MAXCLIENTS 2000

int clients[MAXCLIENTS];
int sockfd;
char *data[MAXCLIENTS]; // 存储临时数据
pthread_mutex_t mutex[MAXCLIENTS];
// gcc 02.task1.c -I ../00.common/ -I../01.thread_pool/ ../01.thread_pool/thread_pool.c  -I ./ ./01.common.c -lpthread

int main(int argc, char **argv)
{

	int opt;
	int port = 7777;
	int server_listen;

	// 反应堆
	int epollfd;

	while ( (opt = getopt(argc, argv, "p:")) != -1)
	{
		switch (opt)
		{
			case 'p':
				port = atoi(optarg);
				break;
			default:
				fprintf(stderr, "usage: %s -p port!\n", argv[0]);
				exit(-1);
		}
	}
	DBG(YELLOW "<D> : server will listen on port [%d].\n"NONE, port);

	if (server_listen = socket_create(port) < 0)
	{
		perror("socket_create");
		exit(-1);
	}
	DBG(YELLOW"<D> : server listen starts.\n"NONE);


	// 锁的初始化
	for (int i = 0; i < MAXCLIENTS; ++i)
	{
		pthread_mutex_init(&mutex[i], NULL);
	}

	struct task_queue *taskQueue = (struct task_queue *)calloc(1, sizeof(struct task_queue));

	for (int i = 0; i < MAXCLIENTS; ++i)
	{
		data[i] = (char *)calloc(1, 4096 + 10);
	}

	task_queue_init(taskQueue, QUEUESIZE);
	DBG(YELLOW"<D> : task queue init sucessfully.\n"NONE);

	pthread_t *tid = (pthread_t *)calloc(INS, sizeof(pthread_t));

	for (int i = 0; i < INS; ++i)
	{
		pthread_create(&tid[i], NULL, worker, (void *)taskQueue);
	}
	DBG(YELLOW"<D> : threads create sucessfully.\n"NONE);

	if ( (epollfd = epoll_create(1)) < 0)
	{
		perror("epoll_create");
		exit(-1);
	}
	struct epoll_event events[MAXEVENTS]; // 关注的事件
	struct epoll_event ev;
	ev.data.fd = server_listen;
	ev.events = EPOLLIN;
	clients[server_listen] = server_listen;

	if (epoll_ctl(epollfd, EPOLL_CTL_ADD, server_listen, &ev) < 0)
	{
		perror("epoll_ctl");
		exit(-1);
	}

	DBG(YELLOW"<D> : server listen is added to epolled sucessfully.\n"NONE);

	for (;;)
	{
		int nfds = epoll_wait(epollfd, events, MAXEVENTS, -1);

		if (nfds < 0)
		{
			perror("epoll_wait");
			exit(-1);
		}

		for (int i = 0; i < nfds; ++i)
		{
			int fd = events[i].data.fd;

			if (fd == server_listen && (events[i].events & EPOLLIN))
			{
				if ( (sockfd == accept(server_listen, NULL, NULL)) < 0)
				{
					perror("accept");
					exit(-1);
				}

				clients[sockfd] = sockfd;
				ev.data.fd = sockfd;
				// ev.events = EPOLLIN | EPOLLET;
				ev.events = EPOLLIN;
				make_nonblock(sockfd);

				if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev) < 0)
				{
					perror("epoll_ctl");
					exit(-1);
				}
				else
				{
					// 已经连接过的

					if (events[i].events & EPOLLIN)
					{
						task_queue_push(taskQueue, (void *)&clients[fd]);
					}
					else
					{
						epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL);
						close(fd);
					}
				}
			}
		}
	}

	return 0;
}