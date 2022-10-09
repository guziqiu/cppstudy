#ifndef _SOCKET_H
#define _SCOKET_H

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "Config.h"

class SspSocket
{
public:
	int Init();

	int SocketAccept();
	int SocketCheckRecv();

	int ClientClose();
	int ServerClose();
private:
	int SocketInit();

public:
	int server_sock;
	struct sockaddr_in server_addr;
	int client_sock;
	struct sockaddr_in client_addr;

	unsigned char recv_buffer[10240];
	unsigned char send_buffer[10240];

	Config config;

	bool accept_flag = false;
};



#endif