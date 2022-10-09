#ifndef _CONFIG_H
#define _CONFIG_H

#include "common/macro.h"

class Config
{
public:
	int ReadConfig();
private:
	GETSETVAR(int, socket_port)
	GETSETSTR(256, socket_addr)
};

#endif