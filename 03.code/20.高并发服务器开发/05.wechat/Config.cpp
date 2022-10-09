
#include <iostream>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
using namespace std;

#include "Config.h"


// Config g_config;

int Config::ReadConfig()
{
	FILE *f = fopen("config.ini", "r");
	if (NULL == f)
	{
		return -1;
	}

	while (true)
	{
		char config_line[256];
		if (fscanf(f, "%ss", config_line) == EOF)
		{
			break;
		}

		if (strstr(config_line, "socket_port") != NULL)
		{
			int port = sscanf(config_line, "socket_port=", &port);
			cout << "port:" << port << endl;
			set_socket_port(port);
		}
		else if (strstr(config_line, "socket_addr") != NULL)
		{
			char sock_addr[256] = {0};
			sscanf(config_line, "socket_addr=", sock_addr);
			cout << "sock_addr:" << sock_addr << endl;
			set_socket_addr(sock_addr);
		}
	}

	fclose(f);
	return 0;
}