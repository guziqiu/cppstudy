
#include <string.h>

#include "Socket.h"

int SspSocket::Init()
{
	config.ReadConfig();
	SocketInit();
	return 0;
}

int SspSocket::SocketInit()
{
	server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(config.socket_port());
	server_addr.sin_addr.s_addr = inet_addr(config.socket_addr());
	bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
	listen(server_sock, 10000);
	return 0;
}

int SspSocket::SocketAccept()
{
	if (accept_flag)
	{
		return 0;
	}

	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	client_sock = accept(server_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);

	accept_flag = true;
	return 0;
}

int SspSocket::SocketCheckRecv()
{
	if (accept_flag)
	{
		return 0;
	}
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	client_sock = accept(server_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

	return 0;
}

int SspSocket::ClientClose()
{
	close(client_sock);
	return 0;
}


int SspSocket::ServerClose()
{
	close(server_sock);
	return 0;
}



