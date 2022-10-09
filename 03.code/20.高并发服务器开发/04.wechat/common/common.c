#include <stdio.h>
#include "head.h"
// #include "common.h"

const char *config = "../wechatd.conf";
struct wechat_user *users;

char ans[512];

int socket_create(int port)
{
	int sockfd;
	struct sockaddr_in server;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		return -1;
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = htonl(INADDR_ANY); // 监听所有

	int resue = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&resue, sizeof(int));

	if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		return -1;
	}

	if (listen(sockfd, 20) < 0)
	{
		return -1;
	}

	return sockfd;
}

int socket_connect(const char *ip, int port)
{
	int sockfd;
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		return -1;
	}

	struct sockaddr_in server;
	bzero(&server, sizeof(server));

	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr(ip);

	if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		return -1;
	}

	return sockfd;
}

int make_nonblock(int fd)
{
	int flags;

	if ((flags == fcntl(fd, F_GETFL)) < 0)
	{
		return -1;
	}

	flags |= O_NONBLOCK;

	return fcntl(fd, F_SETFL, flags);
}

int make_block(int fd)
{
	int flags;

	if ((flags == fcntl(fd, F_GETFL)) < 0)
	{
		return -1;
	}

	flags &= ~O_NONBLOCK;

	return fcntl(fd, F_SETFL, flags);
}

char *get_conf_val(const char *file, const char *key)
{
	FILE *fp;
	char *line = NULL;
	char *sub = NULL; // 找到的指针
	ssize_t len = 0, nread = 0;
	// char ans[512] = {0};

	if ((fp = fopen(file, "r")) == NULL)
	{
		return NULL;
	}

	bzero(ans, sizeof(ans));
	while ((nread = getline(&line, &len, fp)) != -1)
	{
		// DBG("line : %s\n", line);
		if ((sub = strstr(line, key)) == NULL)
			continue; // 没找到

		// DBG("sub = %s\n", sub);
		if (sub == line && line[strlen(key)] == '=')
		{
			// DBG("port = %s\n", ans);
			strcpy(ans, line + strlen(key) + 1);
			if (ans[strlen(ans) - 1] == '\n')
			{
				ans[strlen(ans) - 1] = '\0';
			}
		}
	}

	fclose(fp);
	free(line);

	if (NULL == ans)
	{
		DBG("not get port \n");
		return NULL;
	}


	if (!strlen(ans))
	{
		return NULL;
	}

	return ans;
}

int get_conf_val_int(const char *file, const char *key)
{
	char *ans = get_conf_val(file, key);


	if (NULL == ans)
	{
		DBG("not get port \n");
		return -1;
	}


	if (!strlen(ans))
	{
		return -1;
	}

	return atoi(ans);
}

