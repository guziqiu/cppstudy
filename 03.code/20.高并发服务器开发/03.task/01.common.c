#include <stdio.h>
#include "00.head.h"

int socket_create(int port)
{
	int sockfd;
	struct sockaddr_in server;
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
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

	if ( listen(sockfd, 20) < 0)
	{
		return -1;
	}

	return sockfd;
}


int make_nonblock(int fd)
{
	int flags;

	if ( (flags == fcntl(fd, F_GETFL) ) < 0)
	{
		return -1;
	}

	flags |= O_NONBLOCK;

	return fcntl(fd, F_SETFL, flags);
}

int make_block(int fd)
{
	int flags;

	if ( (flags == fcntl(fd, F_GETFL) ) < 0)
	{
		return -1;
	}

	flags &= ~O_NONBLOCK;

	return fcntl(fd, F_SETFL, flags);
}



