#include "head.h"
#include "common.h"
#include "wechat.h"

const char *config = "../wechatd.conf";

int main(int argc, char **argv)
{

	int opt = 0;
	int server_port = 0;
	int sex = -1;
	char server_ip[20] = {0};
	char name[50] = {0};

	int mode = 0;
	while ( ( opt = getopt(argc, argv, "p:h:s:n:m:") ) != -1 )
	{
		switch (opt)
		{
			case 'p':
				server_port = atoi(optarg);
				break;
			case 'h':
				strcpy(server_ip, optarg);
				break;
			case 'n':
				strcpy(name, optarg);
				break;
			case 'm':
				mode = atoi(optarg);
			case 's':
				sex = atoi(optarg);
				break;
			default:
				fprintf(stderr, "Usage : %s -p port -n name -s sex -h server_ip.\n", argv[0]);
				exit(-1);
		}
	}

	if (access(config, R_OK))
	{
		fprintf(stderr, "config file error\n");
		exit(-1);
	}

	if (!server_port)
	{
		server_port = atoi(get_conf_val(config, "SERVER_PORT"));
	}

	if (-1 == sex)
	{
		sex = atoi(get_conf_val(config, "SEX"));
	}

	if (!strlen(name))
	{
		strcpy(name, get_conf_val(config, "NAME"));
	}

	if (!strlen(server_ip))
	{
		strcpy(server_ip, get_conf_val(config, "SERVER_IP"));
	}

	DBG("server_ip: %s \n server_port: %d \n name: %s.\n", server_ip, server_port, name);
	DBG("read config sucess.\n");

	int sockfd;
	if ( (sockfd = socket_connect(server_ip, server_port)) < 0 )
	{
		perror("sock_connect");
		exit(-1);
	}

	DBG("connect to server %s:%d -> <%d> successfully\n", server_ip, server_port, sockfd);


	struct wechat_msg msg;
	bzero(&msg, sizeof(msg));
	strcpy(msg.from, name);
	msg.sex = sex;
	if (0 == mode)
	{
		// signup
		msg.type = WECHAT_SIGNUP;
	}
	else
	{
		// sigin
		msg.type = WECHAT_SININ;
	}
	send(sockfd, (void *)&msg, sizeof(msg), 0);

	fd_set rfds;
	FD_ZERO(&rfds);
	FD_SET(sockfd, &rfds);

	struct timeval tv;
	tv.tv_sec = 2;
	tv.tv_usec = 0;
	if (select (sockfd + 1, &rfds, NULL, NULL, &tv) <= 0)
	{
		fprintf(stderr, "server is out of service\n");
		exit(-1);
	}

	bzero(&msg, sizeof(msg));
	int ret = recv(sockfd, (void *)&msg, sizeof(msg), 0);
	if (ret <= 0)
	{
		fprintf(stderr, "server close connection.\n");
		exit(-1);
	}

	if (msg.type & WECHAT_ACK)
	{
		DBG("server return a sucess\n");
		if (!mode)
		{
			printf("please login after this.\n");
			exit(0);
		}
	}
	else
	{
		DBG("server return a failure\n");
		close(sockfd);
		exit(-1);
	}

	DBG("login success!\n"); // ./client -m 1 登录

	pthread_t tid;
	pthread_create(&tid, NULL, client_recv, (void *)&sockfd);

	while (1)
	{
		printf("please Input:\n");
		char buff[1024] = {0};
		scanf("%[^\n]", buff);
		getchar();
		if (strlen(buff)) continue;
		msg.type = WECHAT_WALL; // 公有消息
		strcpy(msg.msg, buff);
		send(sockfd, (void *)&msg, sizeof(msg), 0);
	}





	// gcc client.c -I ../ ../common.c ../wechat.c -D _D -lpthread
	return 0;
}